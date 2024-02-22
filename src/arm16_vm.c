#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../Headers/gate_operation.h"
#include "../Headers/operation.h"
#include "../Headers/mnemonics.h"

#define NOT(x) ((~(x)) & 0xF)

enum registers reg_name_to_enum(const char* reg_name) {
    if (reg_name[0] == 'R') {
        uint16_t reg_num = atoi(reg_name + 1);
        return (enum registers)reg_num;
    }
    return -1; // Return -1 for error
}
#define MAX_LABELS 300
struct label
{
    char name[250];
    uint16_t lines_number;
    uint16_t start_line;
    uint16_t end_line;
}labels[MAX_LABELS];
uint16_t label_count = 0;
uint16_t current_end_line = 0;
uint16_t current_start_line = 0;

void execute_instruction(const char *instruction,  int line)
{
     char op[15];

    arm_regs[R_PC]++; // Increment the program counter

    if(instruction[strlen(instruction) - 1] == ';') {
        strncpy(op, instruction, strlen(instruction) - 1);
        op[strlen(instruction)] = '\0';
        if(label_count > 0) {
            labels[label_count - 1].end_line = line - 1;
        }
        op[strlen(instruction) - 1] = '\0';
        strcpy(labels[label_count].name, op);
        labels[label_count].start_line = line;
        label_count++;
       // arm_regs[R_PC]++;  // Increment the program counter
        return;
    }

    char dest[8];
    char op1[3];
    char op2[3];
    uint16_t op1_val = 0;
    uint16_t op2_val = 0;
    sscanf(instruction, "%s %s %s %s", op, dest, op1, op2);

    // Convert register names to enum values

    // Convert register names to enum values
    enum registers dest_reg = reg_name_to_enum(dest);
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
        printf("  result = %d \n", (int)arm_regs[dest_reg]);
    } else if (strcmp(op, "SUB:") == 0) {
        arm_regs[dest_reg] = SUB(op1_val, op2_val);
        printf("  result = %d \n", (int)arm_regs[dest_reg]);
    } else if (strcmp(op, "MUL:") == 0) {
        arm_regs[dest_reg] = MUL(op1_val, op2_val);
        printf("  result = %d \n", (int)arm_regs[dest_reg]);
    } else if (strcmp(op, "DIV:") == 0) {
        if (op2_val != 0) {  // Check for division by zero
            arm_regs[dest_reg] = DIV(op1_val, op2_val);
            printf("  result = %d \n", (int)arm_regs[dest_reg]);
        } else {
            printf("Error: Division by zero\n");
        }
    } else if (strcmp(op, "MOV:") == 0) {
        arm_regs[dest_reg] = MOV(dest_reg, op1_val);
        printf("  mov = %d \n", (int)arm_regs[dest_reg]);
    } else if (strcmp(op, "AND:") == 0) {
        arm_regs[dest_reg] = AND(op1_val, op2_val);
        printf("  result = %d \n", (int)arm_regs[dest_reg]);
    } else if (strcmp(op, "OR:") == 0) {
        arm_regs[dest_reg] = OR(op1_val, op2_val);
        printf("  result = %d \n", (int)arm_regs[dest_reg]);
    } else if (strcmp(op, "XOR:") == 0) {
        arm_regs[dest_reg] = XOR(op1_val, op2_val);
        printf("  result = %d \n", (int)arm_regs[dest_reg]);
    } else if (strcmp(op, "NOT:") == 0) {
        arm_regs[dest_reg] = NOT(op1_val);
        printf("  result = %d \n", (int)arm_regs[dest_reg]);
    } else if (strcmp(op, "LOAD:") == 0) {
        LOAD(dest_reg, op1_val);
        printf("  Loaded value from memory address in %d to %d\n", dest_reg, (int)op1_val);
    } else if (strcmp(op, "STORE:") == 0) {
        STORE(dest_reg, op1_val);
        printf("  Stored value from %d to memory address in %d\n", dest_reg, (int)op1_val);
    } else if (strcmp(op, "JMP:") == 0) {
        // This is a jump instruction
        char target_label[256];
        sscanf(instruction, "    JMP: %s", target_label);
        printf("Debug: target_label = %s\n", target_label); // Add this line to check if the label is recognized
        for (int i = 0; i < label_count; i++) {
            if (strcmp(labels[i].name, target_label) == 0) {
                // Found the target label
                arm_regs[R_PC] = labels[i].start_line;
                current_end_line = labels[i].end_line;
                uint16_t current_line = labels[i].start_line;

                return;
            }
        }
        printf("Error: Label not found: %s\n", target_label);
        exit(1);
    }else {
        // Handle other operations if needed
        printf("Unsupported operation: %s\n", op);
        exit(1);
    }

}


int main()
{

   char line[360];
   char op[15];

    FILE *file = fopen("Arm_Assembly.txt", "r+");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }


    printf("Welcome to the ARM assembly interpreter!\n");

    uint16_t current_line = 0;
    for (int i = 0; i < 16; i++) {
        arm_regs[i] = 0;
    }

    // First pass: record labels
    while (fgets(line, sizeof(line), file) != NULL)
    {
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

        if(line[strlen(line) - 1] == ';') {
            strncpy(op, line, strlen(line) - 1);
            op[strlen(line) - 1] = '\0';
            if(label_count > 0)
            {
                labels[label_count - 1].end_line = current_line - 1;
            }
            strcpy(labels[label_count].name, op);
            labels[label_count].start_line = current_line;
            label_count++;
        }
        current_line++;

    }

    printf("\nRecorded Labels:\n");
    for (int i = 0; i < label_count; i++) {
        printf("Label Name: %s, Start Line: %d, End Line: %d\n", labels[i].name, labels[i].start_line, labels[i].end_line);
    }
    // Reset file and line counter for second pass
    fseek(file, 0, SEEK_SET);
    current_line = 0;

    // Second pass: execute instructions
    char *line_ptr = NULL;

    while (true)
    {
        if (arm_regs[R_PC] == current_line) {
            line_ptr = fgets(line, sizeof(line), file);
            if (line_ptr == NULL) {
                break; // Exit the loop if there are no more lines
            }
            size_t len = strlen(line);
            if (len > 0 && line[len - 1] == '\n') {
                line[len - 1] = '\0';
            }
            printf("%s\n", line);
            current_line++;
            execute_instruction(line, current_line);
        }
        // Only increment current_line if it matches R_PC
        if (arm_regs[R_PC] != current_line)
        {
            // Seek to the start of the file
            fseek(file, 0, SEEK_SET);
            current_line = 0;
            // Read lines until we reach the line corresponding to the new R_PC
            while (current_line < arm_regs[R_PC] && fgets(line, sizeof(line), file) != NULL) {
                current_line++;
            }
        }
    }

    printf("Number of lines executed: %d\n", current_line);
    fclose(file);
    // Print all recorded labels

    return 0;
}