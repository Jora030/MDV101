#include <verilated.h>
#include "Vkey_lock_fsm.h"
#include <cstdio>
#include <verilated_vcd_c.h>

void test_sequence(Vkey_lock_fsm *dut, VerilatedVcdC* tfp, int sequence[], int length, bool expected) {
    dut->reset = 1;
    dut->eval();
    tfp->dump(Verilated::time()); // Запись состояния в VCD
    Verilated::timeInc(1);
    dut->reset = 0;

    for (int i = 0; i < length; i++) {
        dut->key_input = sequence[i];
        dut->eval();
        tfp->dump(Verilated::time()); // Запись состояния в VCD
        Verilated::timeInc(1);
    }

    if (dut->locked == expected) {
        printf("Test Passed\n");
    } else {
        printf("Test Failed\n");
    }
    tfp->dump(Verilated::time());
    Verilated::timeInc(1);
}

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);
    Vkey_lock_fsm *dut = new Vkey_lock_fsm;

    VerilatedVcdC* tfp = new VerilatedVcdC;
    dut->trace(tfp, 99);
    tfp->open("trace.vcd");

    int correct_sequence[] = {3, 3, 5, 2, 5, 6};
    int wrong_sequence[] = {3, 3, 5, 9, 5, 6};

    printf("Testing correct sequence...\n");
    test_sequence(dut, tfp, correct_sequence, 6, 0);

    printf("Testing wrong sequence...\n");
    test_sequence(dut, tfp, wrong_sequence, 6, 1);

    tfp->close();
    delete dut;
    return 0;
}


