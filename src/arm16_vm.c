#include <string.h> // For string manipulation functions like strlen, strcpy, etc.
#include <stdio.h> // For standard input and output functions like printf, fgets, etc.
#include <stdlib.h> // For standard library functions like atoi, exit, etc.
#include "../Headers/gate_operation.h" // Include user-defined header file for gate operations
#include "../Headers/operation.h" // Include user-defined header file for operations
#include "../Headers/mnemonics.h" // Include user-defined header file for mnemonics

#define NOT(x) ((~(x)) & 0xF) // Define macro for bitwise NOT operation
#define MAX_LABELS 300 // Maximum number of labels

// Function to convert register name to enum value
enum registers reg_name_to_enum(const char* reg_name) {
    if (reg_name[0] == 'R') { // If register name starts with 'R'
        uint16_t reg_num = atoi(reg_name + 1); // Extract the register number
        return (enum registers)reg_num; // Return the corresponding enum value
    }
    return -1; // Return -1 for error if the register name doesn't follow expected format
}


// Structure to represent a label
struct label {
    char name[256]; // Name of the label
    uint16_t lines_number; // Line number
    uint16_t start_line; // Start line number
    uint16_t end_line; // End line number
} labels[MAX_LABELS]; // Array to store labels

uint16_t label_count = 0; // Counter for number of labels
uint16_t current_end_line = 0; // End line number for current label
uint16_t current_start_line = 0; // Start line number for current label

// Function to execute an instruction
void execute_instruction(const char *instruction, int line) {
    char op[15]; // Operation

    arm_regs[R_PC]++; // Increment the program counter

    // Check if the instruction is a label
    if(instruction[strlen(instruction) - 1] == ';') {
        // This is a label
        strncpy(op, instruction, strlen(instruction) - 1); // Copy instruction without semicolon
        op[strlen(instruction)] = '\0'; // Terminate the string

        // Update end line for previous label if there was one
        if(label_count > 0) {
            labels[label_count - 1].end_line = line - 1;
        }

        op[strlen(instruction) - 1] = '\0'; // Terminate the string at semicolon
        strcpy(labels[label_count].name, op); // Copy label name
        labels[label_count].start_line = line; // Set start line for current label
        label_count++; // Increment label count

        return; // Exit function
    }

    // Other instructions
    char dest[8]; // Destination
    char op1[3]; // Operand 1
    char op2[3]; // Operand 2
    uint16_t op1_val = 0; // Operand 1 value
    uint16_t op2_val = 0; // Operand 2 value
    sscanf(instruction, "%s %s %s %s", op, dest, op1, op2); // Parse instruction

    // Convert register names to enum values
    enum registers dest_reg = reg_name_to_enum(dest);

    // Parse operand 1
    if (op1[0] == 'R') {
        op1_val = arm_regs[reg_name_to_enum(op1)]; // Get value from register
    } else {
        op1_val = atoi(op1); // Convert operand to integer
    }

    // Parse operand 2
    if (op2[0] == 'R') {
        op2_val = arm_regs[reg_name_to_enum(op2)]; // Get value from register
    } else {
        op2_val = atoi(op2); // Convert operand to integer
    }

    // Execute the corresponding operation
    if (strcmp(op, "ADD:") == 0)
    {
        arm_regs[dest_reg] = ADD(op1_val, op2_val);
        printf("     %s = %d \n", dest, arm_regs[dest_reg]);
    } else if (strcmp(op, "SUB:") == 0) {
        arm_regs[dest_reg] = SUB(op1_val, op2_val);
        printf("     %s = %d \n", dest, arm_regs[dest_reg]);
    } else if (strcmp(op, "MUL:") == 0) {
        arm_regs[dest_reg] = MUL(op1_val, op2_val);
        printf("     %s = %d \n", dest, arm_regs[dest_reg]);
    } else if (strcmp(op, "DIV:") == 0) {
        if (op2_val != 0) {  // Check for division by zero
            arm_regs[dest_reg] = DIV(op1_val, op2_val);
            printf("     %s = %d \n", dest, arm_regs[dest_reg]);
        } else {
            printf("Error: Division by zero\n");
        }
    }
    else if (strcmp(op, "JE:") == 0)
    {
        char target_label[256];
        sscanf(instruction, "JE: %s", target_label);
        if (flags == 0)
        { // Check if the zero flag is set
            for (int i = 0; i < label_count; i++)
            {
                if (strcmp(labels[i].name, target_label) == 0)
                {
                    // Found the target label
                    arm_regs[R_PC] = labels[i].lines_number;
                    return;
                }
            }
            printf("Error: Label not found: %s\n", target_label);
            exit(1);
        }
    }
    else if (strcmp(op, "MOV:") == 0)
    {
        arm_regs[dest_reg] = MOV(dest_reg, op1_val);
        printf("     %s = %d \n", dest, arm_regs[dest_reg]);
    } else if (strcmp(op, "AND:") == 0) {
        arm_regs[dest_reg] = AND(op1_val, op2_val);
        printf("     %s = %d \n", dest, arm_regs[dest_reg]);
    } else if (strcmp(op, "OR:") == 0) {
        arm_regs[dest_reg] = OR(op1_val, op2_val);
        printf("     %s = %d \n", dest, arm_regs[dest_reg]);
    } else if (strcmp(op, "XOR:") == 0) {
        arm_regs[dest_reg] = XOR(op1_val, op2_val);
        printf("     %s = %d \n", dest, arm_regs[dest_reg]);
    } else if (strcmp(op, "NOT:") == 0) {
        arm_regs[dest_reg] = NOT(op1_val);
        printf("     %s = %d \n", dest, arm_regs[dest_reg]);
    } else if (strcmp(op, "LOAD:") == 0) {
        LOAD(dest_reg, op1_val);
        printf("  Loaded value from memory address in %d to %d\n", dest_reg, op1_val);
    } else if (strcmp(op, "STORE:") == 0) {
        STORE(dest_reg, op1_val);
        printf("  Stored value from %d to memory address in %d\n", dest_reg, op1_val);
    } else if (strcmp(op, "CMP:") == 0) {
        arm_regs[dest_reg] = CMP(reg_name_to_enum(op1), reg_name_to_enum(op2));
        printf("     %s = %d \n", dest, arm_regs[dest_reg]);
    } else if (strcmp(op, "JMP:") == 0) {
        char target_label[256];
         sscanf(instruction, "    JMP: %s", target_label);
        printf("\nGoing to the target_label: %s\n\n", target_label);
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
    }else if (strcmp(op, "CALL:") == 0) {
        char target_label[256];
        sscanf(instruction, "    CALL: %s", target_label);
        for (int i = 0; i < label_count; i++) {
            if (strcmp(labels[i].name, target_label) == 0) {
                // Found the target label
                push(arm_regs[R_PC]); // Push the current PC to the stack
                arm_regs[R_PC] = labels[i].start_line; // Jump to the label
                return;
            }
        }
        printf("Error: subroutine not found: %s\n", target_label);
        exit(1);
    }
    else if (strcmp(op, "RET") == 0) {
        arm_regs[R_PC] = pop(); // Pop the return address from the stack and jump back to it
        return;
    }else if (strcmp(op, "MOV:") == 0) {
        arm_regs[dest_reg] = MOV(dest_reg, op1_val); // Execute MOV operation
        printf("  mov = %d \n", arm_regs[dest_reg]); // Print result
    } else if (strcmp(op, "AND:") == 0) {
        arm_regs[dest_reg] = AND(op1_val, op2_val); // Execute AND operation
        printf("  result = %d \n", arm_regs[dest_reg]); // Print result
    } else if (strcmp(op, "OR:") == 0) {
        arm_regs[dest_reg] = OR(op1_val, op2_val); // Execute OR operation
        printf("  result = %d \n", arm_regs[dest_reg]); // Print result
    } else if (strcmp(op, "XOR:") == 0) {
        arm_regs[dest_reg] = XOR(op1_val, op2_val); // Execute XOR operation
        printf("  result = %d \n", arm_regs[dest_reg]); // Print result
    } else if (strcmp(op, "NOT:") == 0) {
        arm_regs[dest_reg] = NOT(op1_val); // Execute NOT operation
        printf("  result = %d \n", arm_regs[dest_reg]); // Print result
    } else if (strcmp(op, "LOAD:") == 0) {
        LOAD(dest_reg, op1_val); // Execute LOAD operation
        printf("  Loaded value from memory address in %d to %d\n", dest_reg, op1_val); // Print result
    } else if (strcmp(op, "STORE:") == 0) {
        STORE(dest_reg, op1_val); // Execute STORE operation
        printf("  Stored value from %d to memory address in %d\n", dest_reg, op1_val); // Print result
    } else if (strcmp(op, "JMP:") == 0) {
        // This is a jump instruction
        char target_label[256];
        sscanf(instruction, "    JMP: %s", target_label); // Extract target label
        printf("Debug: target_label = %s\n", target_label); // Debug information
        for (int i = 0; i < label_count; i++) {
            if (strcmp(labels[i].name, target_label) == 0) {
                // Found the target label
                arm_regs[R_PC] = labels[i].start_line; // Jump to the target label
                current_end_line = labels[i].end_line; // Update end line
                uint16_t current_line = labels[i].start_line; // Update current line
                return; // Exit function
            }
        }
        printf("Error: Label not found: %s\n", target_label); // Print error message if label not found
    } else {
        // Handle unsupported operation
        printf("Unsupported operation: %s\n", op); // Print error message
        exit(1); // Exit program
    }
}

int main() {
    char line[360]; // Buffer for reading lines from file
    char op[15]; // Buffer for storing operation

    FILE *file = fopen("Arm_Assembly.txt", "r+"); // Open file for reading and writing
    if (file == NULL) {
        perror("Error opening file"); // Print error message if file cannot be opened
        return 1; // Exit program
    }

    printf("Welcome to the ARM assembly interpreter!\n"); // Print welcome message


    printf("\n\nSimple Assembly Interpreter!\n\n\n");

    uint16_t current_line = 0;

    for (int i = 0; i < 16; i++) {
        arm_regs[i] = 0; // Initialize all ARM registers to 0
    }

    // First pass: record labels
    while (fgets(line, sizeof(line), file) != NULL) {
        size_t len = strlen(line); // Get length of current line
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0'; // Remove newline character
        }

        // Check if the line ends with a semicolon (label)
        if(line[strlen(line) - 1] == ';') {
            strncpy(op, line, strlen(line) - 1); // Copy line without semicolon
            op[strlen(line) - 1] = '\0'; // Terminate the string
            if(label_count > 0) {
                labels[label_count - 1].end_line = current_line - 1; // Set end line for previous label
            }
            strcpy(labels[label_count].name, op); // Copy label name
            labels[label_count].start_line = current_line; // Set start line for current label
            label_count++; // Increment label count
        }
        current_line++; // Increment current line number
    }

    // Reset file and line counter for second pass
    fseek(file, 0, SEEK_SET); // Set file pointer to the beginning of the file
    current_line = 0; // Reset current line number

    // Second pass: execute instructions
    char *line_ptr = NULL;
    while (true) {
        if (arm_regs[R_PC] == current_line) {
            line_ptr = fgets(line, sizeof(line), file); // Read line from file
            if (line_ptr == NULL) {
                break; // Exit the loop if there are no more lines
            }
            size_t len = strlen(line); // Get length of current line
            if (len > 0 && line[len - 1] == '\n') {
                line[len - 1] = '\0'; // Remove newline character
            }
            printf("%s\n", line); // Print the current line
            current_line++; // Increment current line number
            execute_instruction(line, current_line); // Execute the current instruction
        }
        // Only increment current_line if it matches R_PC
        if (arm_regs[R_PC] != current_line) {
            fseek(file, 0, SEEK_SET); // Seek to the start of the file
            current_line = 0; // Reset current line number
            while (current_line < arm_regs[R_PC] && fgets(line, sizeof(line), file) != NULL) {
                current_line++; // Read lines until we reach the line corresponding to the new R_PC
            }
        }
    }
    for (int i = 0; i < 16; i++) {
        printf("\nRegister R%d: %d\n", i, arm_regs[i]);
    }

    fclose(file);


    return 0; // Exit program
}