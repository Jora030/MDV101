
#include "Valu.h"
#include "verilated.h"
#include <iostream>

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Valu* alu = new Valu;

    alu->a = 0x1111;
    alu->b = 0x0101;

    for (int i = 0; i < 8; ++i) {
        alu->op = i;
        alu->eval();
        std::cout << "op = " << i << ", result = 0x" << std::hex << alu->result << std::endl;
    }

    delete alu;
    return 0;
}
