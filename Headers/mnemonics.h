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


uint16_t MOV(uint16_t registerIndex, uint16_t memoryLocation)
{
    registers[registerIndex] = memory[memoryLocation];
    return 0;
}

uint16_t CALL(int address)
{
    // Save the current state
    stack[++sp] = bp;          // base pointer
    stack[++sp] = ip;          // return address
    bp = sp;
    ip = address;
    return 0;
}


uint16_t CMP(int registerIndex1, int registerIndex2)
{
    if (registers[registerIndex1] == registers[registerIndex2])
    {
        flags = 1;
    }
    else
    {
        flags = 2;
    }
    return 0;
}

uint16_t LOAD(int registerIndex, int memoryLocation)
{
    registers[registerIndex] = memory[memoryLocation];
    return 0;
}

uint16_t STORE(int registerIndex, int memoryLocation)
{
    memory[memoryLocation] = registers[registerIndex];
    return 0;
}



uint16_t JMP(int address)
{
    ip = address;
    return 0;
}

uint16_t JE(int address)
{
    if (flags == 1)
    {
        ip = address;
    }
    return 0;
}

uint16_t RET()
{
    int return_value = stack[sp--];
    sp = bp;                // deleting everything above the bp
    ip = stack[sp--];
    bp = stack[sp--];
    sp -= stack[sp--];
    stack[++sp] = return_value;
    return 0;
}


#endif