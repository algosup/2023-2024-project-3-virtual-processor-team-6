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
uint16_t LOAD(int registerIndex, int memoryLocation);
uint16_t STORE(int registerIndex, int memoryLocation);
uint16_t CMP(int registerIndex1, int registerIndex2);
uint16_t JMP(int address);
uint16_t JE(int address);
uint16_t CALL(int address);
uint16_t RET();


uint16_t MOV(uint16_t memoryLocation, uint16_t registerIndex)
{
   return memoryLocation = registerIndex;
}


uint16_t CMP(int registerIndex1, int registerIndex2)
{
    if (registerIndex1 == registerIndex2)
    {
        flags = 1;
    }
    else
    {
        flags = 0;
    }
    return 0;
}

uint16_t JMP(int address)
{
    return address;
}

uint16_t JE(int address)
{
    if (flags == 1)
    {
        return address;
    }
    else
    {
        return 0;
    }
}

uint16_t RET()
{
    return 0;
}


#endif