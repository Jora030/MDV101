#include <svdpi.h>
#include <stdio.h>

extern "C" int eval_instruction(int inst) {
    printf("Instruction: 0x%04x\n", inst & 0xFFFF);
    return inst;
}
