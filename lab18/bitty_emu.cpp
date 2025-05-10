#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <sstream>
#include <iomanip>

uint16_t emulate_instruction(uint16_t instruction, uint16_t& reg, uint16_t& cmp_result, size_t& pc, bool& is_branch) {
    uint16_t opcode = instruction & 0x0007;
    uint16_t format = instruction & 0x0003;

    is_branch = false;

    if (format == 0b10) {
        uint16_t cond = (instruction >> 2) & 0x3;
        uint16_t target = instruction >> 4;

        if (cmp_result == cond) {
            pc = target;
        } else {
            pc += 1;
        }

        is_branch = true;
        return reg;
    }

    uint16_t before = reg;
    switch (opcode) {
        case 0: reg = reg + 1; break;
        case 1: reg = reg - 1; break;
        case 2: reg = reg ^ 0xFFFF; break;
        case 3: reg = reg & 0x0FFF; break;
        case 4: reg = reg << 1; break;
        case 5: reg = reg >> 1; break;
        case 6: reg = reg | 0x00FF; break;
        case 7: reg = 0; break;
        default: break;
    }

    if (before == reg) cmp_result = 0;
    else if (before > reg) cmp_result = 1;
    else cmp_result = 2;

    pc += 1;
    return reg;
}

int main() {
    std::ifstream file("prog.hex");
    if (!file) {
        std::cerr << "Failed to open prog.hex\n";
        return 1;
    }

    std::vector<uint16_t> instructions;
    std::string line;
    while (std::getline(file, line)) {
        uint16_t instr;
        std::stringstream ss;
        ss << std::hex << line;
        ss >> instr;
        instructions.push_back(instr);
    }

    uint16_t reg = 0;
    uint16_t cmp_result = 0;
    size_t pc = 0;
    int step = 0;

    while (pc < instructions.size()) {
        uint16_t instr = instructions[pc];
        bool is_branch = false;
        uint16_t result = emulate_instruction(instr, reg, cmp_result, pc, is_branch);

        std::cout << "T=" << std::setw(2) << std::setfill('0') << step++
                  << " PC=" << std::setw(4) << std::hex << pc
                  << " INSTR=" << std::setw(4) << instr
                  << " REG=" << std::setw(4) << reg
                  << " CMP=" << cmp_result
                  << (is_branch ? " [BRANCH]" : "")
                  << std::endl;
    }

    return 0;
}
