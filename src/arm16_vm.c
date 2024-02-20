#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../Headers/gate_operation.h"
#include "../Headers/operation.h"
#include "../Headers/mnemonics.h"


#define NOT(x) ((~(x)) & 0xF)

enum registers reg_name_to_enum(const char* reg_name) {
    if (reg_name[0] == 'R') {
        int reg_num = atoi(reg_name + 1);
        return (enum registers)reg_num;
    }
    return -1; // Return -1 for error
}
#define MAX_LABELS 300
struct label
{
    char name[250];
    int lines_number;
}labels[MAX_LABELS];
int label_count = 0;

void execute_instruction(const char *instruction,  int line)
{
    char op[5];
    if(instruction[strlen(instruction) - 1] == '|') {
        // This is a label
        strncpy(op, instruction, strlen(instruction) - 1);
        op[strlen(instruction) - 1] = '\0';
        strcpy(labels[label_count].name, op);
        labels[label_count].lines_number = line;
        label_count++;
        return;
    }

    char dest[4];
    char op1[3];
    char op2[3];
    sscanf(instruction, "%s %s %s %s", op, dest, op1, op2);

    // Convert register names to enum values

    // Convert register names to enum values
    enum registers dest_reg = reg_name_to_enum(dest);
    uint16_t op1_val;
    uint16_t op2_val;

    if (op1[0] == 'R') {
        op1_val = arm_regs[reg_name_to_enum(op1)];
    } else {
        op1_val = atoi(op1);
    }

    if (op2[0] == 'R') {
        op2_val = arm_regs[reg_name_to_enum(op2)];
    } else {
        op2_val = atoi(op2);
    }



        // Execute the corresponding operation
    if (strcmp(op, "ADD:") == 0) {
        arm_regs[dest_reg] = ADD(op1_val, op2_val);
        printf("  result = %d \n", arm_regs[dest_reg]);
    } else if (strcmp(op, "SUB:") == 0) {
        arm_regs[dest_reg] = SUB(op1_val, op2_val);
        printf("  result = %d \n", arm_regs[dest_reg]);
    } else if (strcmp(op, "MUL:") == 0) {
        arm_regs[dest_reg] = MUL(op1_val, op2_val);
        printf("  result = %d \n", arm_regs[dest_reg]);
    } else if (strcmp(op, "DIV:") == 0) {
        if (op2_val != 0) {  // Check for division by zero
            arm_regs[dest_reg] = DIV(op1_val, op2_val);
            printf("  result = %d \n", arm_regs[dest_reg]);
        } else {
            printf("Error: Division by zero\n");
        }
    } else if (strcmp(op, "JE:") == 0) {
    char target_label[256];
    sscanf(instruction, "JE: %s", target_label);
    if (flags == 0) { // Check if the zero flag is set
        for (int i = 0; i < label_count; i++) {
            if (strcmp(labels[i].name, target_label) == 0) {
                // Found the target label
                arm_regs[R_PC] = labels[i].lines_number;
                return;
            }
        }
        printf("Error: Label not found: %s\n", target_label);
        exit(1);
    }
    } else if (strcmp(op, "MOV:") == 0) {
        arm_regs[dest_reg] = MOV(dest_reg, op1_val);
        printf("  mov = %d \n", arm_regs[dest_reg]);
    } else if (strcmp(op, "AND:") == 0) {
        arm_regs[dest_reg] = AND(op1_val, op2_val);
        printf("  result = %d \n", arm_regs[dest_reg]);
    } else if (strcmp(op, "OR:") == 0) {
        arm_regs[dest_reg] = OR(op1_val, op2_val);
        printf("  result = %d \n", arm_regs[dest_reg]);
    } else if (strcmp(op, "XOR:") == 0) {
        arm_regs[dest_reg] = XOR(op1_val, op2_val);
        printf("  result = %d \n", arm_regs[dest_reg]);
    } else if (strcmp(op, "NOT:") == 0) {
        arm_regs[dest_reg] = NOT(op1_val);
        printf("  result = %d \n", arm_regs[dest_reg]);
    } else if (strcmp(op, "LOAD:") == 0) {
        LOAD(dest_reg, op1_val);
        printf("  Loaded value from memory address in %d to %d\n", dest_reg, op1_val);
    } else if (strcmp(op, "STORE:") == 0) {
        STORE(dest_reg, op1_val);
        printf("  Stored value from %d to memory address in %d\n", dest_reg, op1_val);
    } else if (strcmp(op, "JUMP:") == 0) {
        // This is a jump instruction
        char target_label[256];
        sscanf(instruction, "JUMP: %s", target_label);
        for (int i = 0; i < label_count; i++) {
            if (strcmp(labels[i].name, target_label) == 0) {
                // Found the target label
                arm_regs[R_PC] = labels[i].lines_number;
                return;
            }
        }
        printf("Error: Label not found: %s\n", target_label);
    }else {
        // Handle other operations if needed
        printf("Unsupported operation: %s\n", op);
        exit(1);
    }

}


int main()
{

   char line[250];

    FILE *file = fopen("Arm_Assembly.txt", "r+");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }


    printf("Welcome to the ARM assembly interpreter!\n");

    int current_line = 0;
    // Adjust the size accordingly
    while (fgets(line, sizeof(line), file) != NULL) {
        if(arm_regs[R_PC] != current_line){
            current_line++;
            continue;
        }
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';

        }
        printf("%s\n", line);

        execute_instruction(line, current_line);

        if(arm_regs[R_PC] == current_line){
            arm_regs[R_PC]++;
        }
        current_line++;
    }

    printf("Number of lines executed: %d\n", current_line);
    fclose(file);

    return 0;
}