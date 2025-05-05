#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vprocessor.h"

vluint64_t main_time = 0;
double sc_time_stamp() { return main_time; }

int get_instruction() {
    return 0x0210;
}

int main(int argc, char **argv, char **env) {
    Verilated::commandArgs(argc, argv);
    Vprocessor* top = new Vprocessor;

    VerilatedVcdC* tfp = new VerilatedVcdC;
    Verilated::traceEverOn(true);
    top->trace(tfp, 99);
    tfp->open("trace.vcd");

    top->rst = 1;
    top->clk = 0;

    for (int i = 0; i < 2; ++i) {
        top->clk = !top->clk;
        top->eval();
        tfp->dump(main_time++);
    }

    top->rst = 0;

    for (int i = 0; i < 10; ++i) {
        top->clk = !top->clk;
        top->eval();
        tfp->dump(main_time++);
    }

    tfp->close();
    delete top;
    return 0;
}
