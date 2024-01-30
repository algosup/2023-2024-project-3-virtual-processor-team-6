#ifndef GATE_OPERATION_H
#define GATE_OPERATION_H

#include <stdlib.h>
#include <stdio.h>

#define MEMORY_MAX (1 << 16)
uint16_t memory[MEMORY_MAX];

uint16_t mem_read(uint16_t address)
{
    return memory[address];
}

enum logic
{
    xor_g,
    and_g,
    or_g,
    not_g,
};

enum registers
{
    R1,
    R2,
    R3,
    R4,
    R5,
    R6,
    R7,
    R8,
    R9,
    R10,
    R11,
    R_IP, // (also known as Intra-Procedure-call scratch register)
    R_SP, // (also known as Stack Pointer)
    R_LR, // (also known as Link Register)
    R_PC, // (also known as Program Counter)
};

uint16_t registers[16];

void XOR(uint16_t reg1, uint16_t reg2)
{
    registers[reg1] = registers[reg1] ^ registers[reg2];
}

void AND(uint16_t reg1, uint16_t reg2)
{
    registers[reg1] = registers[reg1] & registers[reg2];
}

void OR(uint16_t reg1, uint16_t reg2)
{
    registers[reg1] = registers[reg1] | registers[reg2];
}

void NOT(uint16_t reg1)
{
    registers[reg1] = ~registers[reg1];
}

#endif