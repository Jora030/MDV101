
#include "Vmux.h"
#include "verilated.h"
#include <iostream>

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vmux* mux = new Vmux;

    for (int i = 0; i < 10; ++i) {
        mux->in[i] = i * 0x1111;
    }

    for (int i = 0; i < 10; ++i) {
        mux->sel = i;
        mux->eval();
        std::cout << "sel = " << i << ", out = 0x" << std::hex << mux->out << std::endl;
    }

    delete mux;
    return 0;
}
