#ifndef OPERATION_H
#define OPERATION_H

#include <stdlib.h>
#include <stdio.h>
#include "gate_operation.h"

uint16_t instruct = 15;

enum operation
{
    OP_add,
    OP_sub,
    OP_div,
    OP_mul,
};

uint16_t ADD(uint16_t rs1, uint16_t rs2) 
{
    return rs1 + rs2;
}

// Function to subtract two values and store the result.
uint16_t SUB(uint16_t rs1, uint16_t rs2)
{ 
    return rs1 - rs2;
}

// Function to divide two values and store the result.
uint16_t DIV(uint16_t rs1, uint16_t rs2)
{
    if (rs2 != 0) {
        return rs1 / rs2;
    } else {
        // Handle division by zero error (you may want to customize this based on your requirements)
        printf("Error: Division by zero\n");
        exit(EXIT_FAILURE);
    }
}

// Function to multiply two values and store the result.
uint16_t MUL(uint16_t rs1, uint16_t rs2)
{
    return rs1 * rs2;
}

#endif
