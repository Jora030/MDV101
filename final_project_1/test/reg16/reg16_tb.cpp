
#include "Vreg16.h"
#include "verilated.h"
#include <iostream>

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    Vreg16 *reg = new Vreg16;

    reg->clk = 0;
    reg->enable = 1;
    reg->d = 0xBEEF;

    reg->clk = 0; reg->eval();
    reg->clk = 1; reg->eval();

    std::cout << "q = " << std::hex << reg->q << std::endl;

    delete reg;
    return 0;
}
