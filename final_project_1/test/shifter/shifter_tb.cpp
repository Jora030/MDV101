
#include "Vshifter.h"
#include "verilated.h"
#include <iostream>

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vshifter* sh = new Vshifter;

    sh->data_in = 0x8001;

    for (int i = 0; i < 4; ++i) {
        sh->op = i;
        sh->eval();
        std::cout << "op = " << i << ", data_out = 0x" << std::hex << sh->data_out << std::endl;
    }

    delete sh;
    return 0;
}
