#ifndef MNEMONICS_H
#define MNEMONICS_H

#include <stdlib.h>
#include <stdio.h>
#include "gate_operation.h"
#define MEMORY_SIZE 100 // Define the memory size constant

enum mnemonics
{
    load,
    store,
    cmp,
    jmp,
    je,
    call,
    ret,
};

int flags; // Declare the flags variable
uint16_t MOV(uint16_t registerIndex, uint16_t memoryLocation);
void LOAD(int registerIndex, int memoryLocation);
void STORE(int registerIndex, int memoryLocation);
void CMP(int registerIndex1, int registerIndex2);
void JMP(int address);
void JE(int address);
void CALL(int address);
void RET();


uint16_t MOV(uint16_t memoryLocation, uint16_t registerIndex)
{
   return memoryLocation = registerIndex;
}

#endif