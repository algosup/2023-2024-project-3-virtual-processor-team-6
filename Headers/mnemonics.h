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

#define MAX_STACK 1000
uint16_t stack[MAX_STACK];

int flags;
uint16_t MOV(uint16_t registerIndex, uint16_t memoryLocation);
void LOAD(enum registers sourceReg, enum registers destReg);
void STORE(enum registers sourceReg, enum registers destReg);
uint16_t CMP(uint16_t registerIndex1, uint16_t registerIndex2);
void push(uint16_t value);
uint16_t pop();


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
void push(uint16_t value) {
    if (arm_regs[R_SP] == MAX_STACK) {
        printf("Error: Stack overflow\n");
        exit(1);
    }
    stack[arm_regs[R_SP]++] = value;
}

uint16_t pop() {
    if (arm_regs[R_SP] == 0) {
        printf("Error: Stack underflow\n");
        exit(1);
    }
    return stack[--arm_regs[R_SP]];
}


uint16_t RET()
{
    return 0;
}




#endif