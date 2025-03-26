
#include "Vcomparator.h"
#include "verilated.h"
#include <iostream>

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vcomparator* cmp = new Vcomparator;

    uint16_t test_vals[][2] = {
        {0x1234, 0x1234},
        {0xFFFF, 0x00FF},
        {0x0001, 0x1000}
    };

    for (int i = 0; i < 3; ++i) {
        cmp->a = test_vals[i][0];
        cmp->b = test_vals[i][1];
        cmp->eval();
        std::cout << "a = " << std::hex << cmp->a
                  << ", b = " << cmp->b
                  << " | eq: " << cmp->eq
                  << ", gt: " << cmp->gt
                  << ", lt: " << cmp->lt << std::endl;
    }

    delete cmp;
    return 0;
}
