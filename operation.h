#ifndef OPERATION_H
#define OPERATION_H

#include <stdlib.h>
#include <stdio.h>
#include "gate_operation.h"

uint16_t instruct = 15;
uint16_t arm_regs[16];

enum operation
{
    OP_add,
    OP_sub,
    OP_div,
    OP_mul,
};

void ADD();
void SUB();
void DIV();
void MUL();

// Function to sign extend a bit field.
uint16_t sign_extend(uint16_t x, int bit_count)
{
    if ((x >> (bit_count - 1)) & 1)
    {
        x |= (0xFFFF << bit_count);
    }
    return x;
}

// Function to add two values and store the result.
void ADD()
{
    uint16_t destReg = (instruct >> 9) & 0x7;
    uint16_t firstReg = (instruct >> 7) & 0x7;
    uint16_t secondReg = (instruct >> 4) & 0x7;
    uint16_t immediateMode = (instruct >> 5) & 0x1;

    if (immediateMode)
    {
        uint16_t imm5 = sign_extend(instruct & 0x1F, 5);
        arm_regs[destReg] = arm_regs[firstReg] + imm5;
    }
    else
    {
        arm_regs[destReg] = arm_regs[firstReg] + arm_regs[secondReg];
    }
}

// Function to subtract two values and store the result.
void SUB()
{
    uint16_t destReg = (instruct >> 9) & 0x7;
    uint16_t firstReg = (instruct >> 7) & 0x7;
    uint16_t secondReg = (instruct >> 4) & 0x7;
    uint16_t immediateMode = (instruct >> 5) & 0x1;

    if (immediateMode)
    {
        uint16_t imm5 = sign_extend(instruct & 0x1F, 5);
        arm_regs[destReg] = arm_regs[firstReg] - imm5;
    }
    else
    {
        arm_regs[destReg] = arm_regs[firstReg] - arm_regs[secondReg];
    }
}

// Function to divide two values and store the result.
void DIV()
{
    uint16_t destReg = (instruct >> 9) & 0x7;
    uint16_t firstReg = (instruct >> 7) & 0x7;
    uint16_t secondReg = (instruct >> 4) & 0x7;

    // Check for division by zero
    if (arm_regs[secondReg] == 0)
    {
        printf("Error: Division by zero\n");
        return;
    }

    arm_regs[destReg] = arm_regs[firstReg] / arm_regs[secondReg];
}

// Function to multiply two values and store the result.
void MUL()
{
    uint16_t destReg = (instruct >> 9) & 0x7;
    uint16_t firstReg = (instruct >> 7) & 0x7;
    uint16_t secondReg = (instruct >> 4) & 0x7;

    arm_regs[destReg] = arm_regs[firstReg] * arm_regs[secondReg];
}

#endif