#include "Vprocessor.h"
#include "verilated.h"
#include <cstdint>
#include <iostream>

vluint64_t main_time = 0;

double sc_time_stamp() {
    return main_time;
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    Vprocessor* top = new Vprocessor;

    top->clk = 0;
    top->reset = 1;

    std::cout << "[SIM] Starting simulation...\n";

    while (!Verilated::gotFinish() && main_time < 1000) {

        if (main_time == 5) top->reset = 0;


        top->clk = !top->clk;
        top->eval();

        main_time++;
    }

    std::cout << "[SIM] Finished after " << main_time << " cycles.\n";

    delete top;
    return 0;
}
