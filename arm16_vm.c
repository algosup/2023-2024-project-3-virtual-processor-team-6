#include <stdlib.h>
#include <stdio.h>
#include "gate_operation.h"
#include "operation.h"

int main(int argc, const char* argv[])
{

    uint16_t arm_regs [16];
    enum
    {
        PC_START = 0x3000
    };

    arm_regs[R_PC] = PC_START;

    int running = 1;

    while(running)
    {
        uint16_t instruct = mem_read(arm_regs[R_PC]++);
        uint16_t op = instruct >> 12;

        switch (op)
        {
        case OP_add:
             ADD();
             break;
        default:
            break;
        }
    }
}