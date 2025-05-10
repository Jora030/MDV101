#include "Vtop.h"
#include "verilated.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <cstdint>

uint16_t emulate_instruction(uint16_t instruction, uint16_t reg) {
    uint16_t opcode = instruction & 0x0007;

    switch (opcode) {
        case 0: return reg + 1;
        case 1: return reg - 1;
        case 2: return reg ^ 0xFFFF;
        case 3: return reg & 0x0FFF;
        case 4: return reg << 1;
        case 5: return reg >> 1;
        case 6: return reg | 0x00FF;
        case 7: return 0;
        default: return reg;
    }
}

std::vector<uint16_t> load_prog(const std::string& filename) {
    std::vector<uint16_t> instructions;
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        uint16_t instr;
        std::stringstream ss;
        ss << std::hex << line;
        ss >> instr;
        instructions.push_back(instr);
    }
    return instructions;
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    Vtop* top = new Vtop;
    std::vector<uint16_t> prog = load_prog("prog.hex");

    uint16_t emu_reg = 0;
    int max_cycles = 1000;
    int pc = 0;

    top->clk = 0;
    top->reset = 1;
    top->eval();

    top->clk = 1;
    top->eval();

    top->reset = 0;

    std::cout << "Starting Co-Simulation...\n";

    for (int cycle = 0; cycle < max_cycles && pc < prog.size(); ++cycle) {
        top->clk = 0;
        top->eval();
        top->clk = 1;
        top->eval();

        if (top->done) {
            uint16_t rtl_result = top->result;
            uint16_t instr = prog[pc];

            uint16_t expected = emulate_instruction(instr, emu_reg);
            std::cout << "PC=" << std::setw(4) << std::setfill('0') << std::hex << pc
                      << " INSTR=" << instr
                      << " EMU_REG(before)=" << emu_reg
                      << " EMU_REG(after)=" << expected
                      << " RTL_RESULT=" << rtl_result;

            if (rtl_result == expected) {
                std::cout << " ✅ PASS\n";
            } else {
                std::cout << " ❌ FAIL\n";
            }

            emu_reg = expected;
            ++pc;
        }
    }

    delete top;
    return 0;
}
