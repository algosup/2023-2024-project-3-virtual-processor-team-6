#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../Headers/gate_operation.h"
#include "../Headers/operation.h"
#include "../Headers/mnemonics.h"

void execute_instruction(const char *instruction)
{

    char op[5];
    char dest[4];
    char op1[3];
    char op2[3];
    sscanf(instruction, "%s %s %s %s", op, dest, op1, op2);

    // Convert register names to enum values

   // Convert register names to enum values
    uint16_t dest_reg = atoi(dest + 1);
    uint16_t op1_val;
    uint16_t op2_val;

    if (op1[0] == 'R') {
        op1_val = arm_regs[atoi(op1 + 1)];
    } else {
        op1_val = atoi(op1);
    }

    if (op2[0] == 'R') {
        op2_val = arm_regs[atoi(op2 + 1)];
    } else {
        op2_val = atoi(op2);
    }


    // Execute the corresponding operation
if (strcmp(op, "ADD:") == 0) {
    arm_regs[dest_reg] = ADD(op1_val, op2_val);
    printf("result = %d \n", arm_regs[dest_reg]);
} else if (strcmp(op, "SUB:") == 0) {
    arm_regs[dest_reg] = SUB(op1_val, op2_val);
    printf("result = %d \n", arm_regs[dest_reg]);
} else if (strcmp(op, "MUL:") == 0) {
    arm_regs[dest_reg] = MUL(op1_val, op2_val);
    printf("result = %d \n", arm_regs[dest_reg]);
} else if (strcmp(op, "DIV:") == 0) {
    if (op2_val != 0) {  // Check for division by zero
        arm_regs[dest_reg] = DIV(op1_val, op2_val);
        printf("result = %d \n", arm_regs[dest_reg]);
    } else {
        printf("Error: Division by zero\n");
    }
} else if (strcmp(op, "MOV:") == 0) {
    arm_regs[dest_reg] = MOV(dest_reg, op1_val);
    printf("mov = %d \n", arm_regs[dest_reg]);
} else {
    // Handle other operations if needed
    printf("Unsupported operation: %s\n", op);
}
    


}

int main()
{

   char line[250];

    // Execute the assembly instructions in the file
   initialize_arm_regs();  // Initialize registers

    FILE *file = fopen("Arm_Assembly.txt", "r+");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }


    printf("Welcome to the ARM assembly interpreter!\n");
    // Adjust the size accordingly
    while (fgets(line, sizeof(line), file) != NULL) {


        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';

        }
        printf("%s\n", line);

        execute_instruction(line);
    }

    fclose(file);

    return 0;
}