#include "Vfibonacci_generator.h"
#include "verilated.h"
#include "verilated_vcd_c.h" 
#include <iostream>

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);

    Vfibonacci_generator *tb = new Vfibonacci_generator;


    Verilated::traceEverOn(true);
    VerilatedVcdC* vcd_trace = new VerilatedVcdC;
    tb->trace(vcd_trace, 99);
    vcd_trace->open("fibonacci_trace.vcd");

  
    vluint64_t sim_time = 0;
    const vluint64_t max_sim_time = 1000;
    bool enable = true;

    tb->clk = 0;
    tb->rst = 1;

    while (sim_time < max_sim_time) {
        tb->clk = !tb->clk;

        if (sim_time == 10) {
            tb->rst = 0;
        }

        tb->enable = enable;
        tb->eval();

        
        vcd_trace->dump(sim_time);

        if (tb->clk && !tb->rst) {
            std::cout << "Cycle " << sim_time / 2 << ": Fibonacci number = " << tb->fib_out << std::endl;
        }

        sim_time++;
    }

    vcd_trace->close();
    tb->final();
    delete tb;
    delete vcd_trace;

    return 0;
}
