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

uint16_t sign_extend(uint16_t x, int bit_count)
{
    if ((x >> (bit_count - 1)) & 1)
    {
        x |= (0xFFFF << bit_count);
    }
    return x;
}

void ADD()
{
    uint16_t R1 = (instruct >> 9) & 0x7; // destination address
    uint16_t R2 = (instruct >> 7) & 0x7; // first register
    uint16_t R3 = (instruct >> 4) & 0x7; // second register
    uint16_t imm_val = (instruct >> 5) & 0x1; //whether we have an immediate mode or not

    if (imm_val)
    {
        uint16_t imm5 = sign_extend(instruct & 0x1F, 5);
        arm_regs[R1] = arm_regs[R2] + imm5;
    }
    else
    {
        arm_regs[R1] = arm_regs[R2] + arm_regs[R3];
    }
}

void SUB()
{
    uint16_t R1 = (instruct >> 9) & 0x7; // destination address
    uint16_t R2 = (instruct >> 7) & 0x7; // first register
    uint16_t R3 = (instruct >> 4) & 0x7; // second register
    uint16_t imm_val = (instruct >> 5) & 0x1; //whether we have an immediate mode or not

    if (imm_val)
    {
        uint16_t imm5 = sign_extend(instruct & 0x1F, 5);
        arm_regs[R1] = arm_regs[R2] - imm5;
    }
    else
    {
        arm_regs[R1] = arm_regs[R2] - arm_regs[R3];
    }
}

void DIV()
{
    uint16_t R1 = (instruct >> 9) & 0x7; // destination address
    uint16_t R2 = (instruct >> 7) & 0x7; // first register
    uint16_t R3 = (instruct >> 4) & 0x7; // second register

    arm_regs[R1] = arm_regs[R2] / arm_regs[R3];
}

void MUL()
{
    uint16_t R1 = (instruct >> 9) & 0x7; // destination address
    uint16_t R2 = (instruct >> 7) & 0x7; // first register
    uint16_t R3 = (instruct >> 4) & 0x7; // second register

    arm_regs[R1] = arm_regs[R2] * arm_regs[R3];
}

#endif
