#ifndef MNEMONICS_H
#define MNEMONICS_H

#include <stdlib.h>
#include <stdio.h>
#include "gate_operation.h"
#define MEMORY_SIZE 100 // Define the memory size constant
#define MAX_LABELS 100
struct
{
    char name[50];
    int lines;
}labels[MAX_LABELS];
int num_labels = 0;


int flags; // Declare the flags variable
uint16_t MOV(uint16_t registerIndex, uint16_t memoryLocation);
uint16_t LOAD(int registerIndex, int memoryLocation);
uint16_t STORE(int registerIndex, int memoryLocation);
uint16_t CMP(int registerIndex1, int registerIndex2);
void JMP(char* dest);
uint16_t JE(uint16_t address);
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



uint16_t JE(uint16_t address)
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