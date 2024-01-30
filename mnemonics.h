#ifndef MNEMONICS_H
#define MNEMONICS_H

#include <stdlib.h>
#include <stdio.h>

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

void LOAD(int registerIndex, int memoryLocation);
void STORE(int registerIndex, int memoryLocation);
void CMP(int registerIndex1, int registerIndex2);
void JMP(int address);
void JE(int address);
void CALL(int address);
void RET();

void LOAD(int registerIndex, int memoryLocation)
{
    registers[registerIndex] = memory[memoryLocation];
};

void STORE(int registerIndex, int memoryLocation)
{
    memory[memoryLocation] = registers[registerIndex];
};

void CMP(int registerIndex1, int registerIndex2)
{
    if (registers[registerIndex1] == registers[registerIndex2])
    {
        flags = 1;
    }
    else if (registers[registerIndex1] > registers[registerIndex2])
    {
        flags = 2;
    }
    else if (registers[registerIndex1] < registers[registerIndex2])
    {
        flags = 3;
    }
};

void JMP(int address)
{
    registers[R_PC] = address;
};

void JE(int address)
{
    if (flags == 1)
    {
        registers[R_PC] = address;
    }
};

void CALL(int address)
{
    registers[R_SP] = registers[R_SP] - 1;
    memory[registers[R_SP]] = registers[R_PC];
    registers[R_PC] = address;
};

void RET()
{
    registers[R_PC] = memory[registers[R_SP]];
    registers[R_SP] = registers[R_SP] + 1;
};

#endif