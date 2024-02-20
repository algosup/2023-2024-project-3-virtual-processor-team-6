#ifndef MNEMONICS_H
#define MNEMONICS_H

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>
#include <time.h>
#include "gate_operation.h"



int flags; 
uint16_t MOV(uint16_t registerIndex, uint16_t memoryLocation);
void LOAD(enum registers sourceReg, enum registers destReg);
void STORE(enum registers sourceReg, enum registers destReg);
uint16_t CMP(uint16_t registerIndex1, uint16_t registerIndex2);
void JMP(char* label_name);
uint16_t JE(uint16_t address);
uint16_t CALL(uint16_t address);
uint16_t RET();


void LOAD(enum registers sourceReg, enum registers destReg) {
    uint16_t address = arm_regs[sourceReg];
    if (address < MEMORY_MAX - 1) {
        arm_regs[destReg] = memory[address];
    } else {
        printf("Error: Memory address out of bounds\n");
    }
}

void STORE(enum registers sourceReg, enum registers destReg) {
    uint16_t address = arm_regs[destReg];
    if (address < MEMORY_MAX - 1) {
        memory[address] = arm_regs[sourceReg];
    } else {
        printf("Error: Memory address out of bounds\n");
    }
}

uint16_t MOV(uint16_t registerIndex, uint16_t value)
{
    arm_regs[registerIndex] = value;
    return arm_regs[registerIndex];
}
u_int16_t JE(u_int16_t address)
{
    if (flags == 0)
    {
        return address;
    }
    return 0;
}

u_int16_t CALL(u_int16_t address)
{
    return address;
}

uint16_t CMP(uint16_t registerIndex1, uint16_t registerIndex2)
{
    if (arm_regs[registerIndex1] == arm_regs[registerIndex2])
    {
        flags = 0;
    }
    else if (arm_regs[registerIndex1] > arm_regs[registerIndex2])
    {
        flags = 1;
    }
    else
    {
        flags = -1;
    }
    return flags;
}

uint16_t RET()
{
    return 0;
}




#endif