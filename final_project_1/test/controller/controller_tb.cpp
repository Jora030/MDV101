
#include "Vcontroller.h"
#include "verilated.h"
#include <iostream>

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vcontroller* ctrl = new Vcontroller;

    ctrl->reset = 1;
    ctrl->clk = 0;
    ctrl->eval();

    ctrl->reset = 0;

    for (int i = 0; i < 8; ++i) {
        ctrl->clk = 0;
        ctrl->eval();
        ctrl->clk = 1;
        ctrl->eval();

        std::cout << "Cycle " << i
                  << " | state = " << (int)ctrl->state
                  << ", alu_op = " << (int)ctrl->alu_op
                  << ", shift_op = " << (int)ctrl->shift_op
                  << std::endl;
    }

    delete ctrl;
    return 0;
}
