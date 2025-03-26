
#include "Vbitty_core.h"
#include "verilated.h"
#include <iostream>

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vbitty_core* core = new Vbitty_core;

    core->reset = 1;
    core->clk = 0;
    core->eval();

    core->reset = 0;

    for (int i = 0; i < 10; ++i) {
        core->clk = 0;
        core->eval();
        core->clk = 1;
        core->eval();

        std::cout << "Cycle " << i
                  << " | state = " << (int)core->state
                  << ", result = " << std::dec << (int16_t)core->result << std::endl;
    }

    delete core;
    return 0;
}
