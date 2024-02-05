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
enum registers
{
    R1 = 0,
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
uint16_t arm_regs[16]; // Increase the size to 16 to accommodate all registers
void initialize_arm_regs() {
    enum {
        PC_START = 0x3000,
    };
    arm_regs[R_PC] = PC_START;
}
uint16_t AND(uint16_t op1, uint16_t op2) {
    return op1 & op2;
}
uint16_t OR(uint16_t op1, uint16_t op2) {
    return op1 | op2;
}
uint16_t XOR(uint16_t op1, uint16_t op2) {
    return op1 ^ op2;
}
uint16_t NOT(uint16_t op1) {
    return ~op1;
}
#endif