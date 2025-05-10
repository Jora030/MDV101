#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <sstream>
#include <iomanip>

uint16_t emulate_instruction(uint16_t instruction, std::vector<uint16_t>& reg, std::vector<uint16_t>& mem, uint16_t& cmp_result, size_t& pc, bool& is_branch) {
    uint16_t format = instruction & 0x0003;
    is_branch = false;

    if (format == 0b10) {
        uint16_t cond = (instruction >> 2) & 0x3;
        uint16_t target = instruction >> 4;
        if (cmp_result == cond) {
            pc = target;
        } else {
            pc++;
        }
        is_branch = true;
        return reg[0];
    } else if (format == 0b11) {
        uint16_t rx = (instruction >> 13) & 0x7;
        uint16_t ry = (instruction >> 10) & 0x7;
        bool is_load = ((instruction >> 2) & 0x1) == 0;

        if (is_load) {
            reg[rx] = mem[reg[ry]];
        } else {
            mem[reg[ry]] = reg[rx];
        }

        pc++;
        return reg[rx];
    }

    uint16_t opcode = instruction & 0x0007;
    uint16_t rx = (instruction >> 13) & 0x7;
    uint16_t ry = (instruction >> 10) & 0x7;
    uint16_t before = reg[rx];

    switch (opcode) {
        case 0: reg[rx] = reg[rx] + 1; break;
        case 1: reg[rx] = reg[rx] - 1; break;
        case 2: reg[rx] = reg[rx] ^ 0xFFFF; break;
        case 3: reg[rx] = reg[rx] & 0x0FFF; break;
        case 4: reg[rx] = reg[rx] << 1; break;
        case 5: reg[rx] = reg[rx] >> 1; break;
        case 6: reg[rx] = reg[rx] | 0x00FF; break;
        case 7: reg[rx] = 0; break;
    }

    if (reg[rx] == reg[ry]) cmp_result = 0;
    else if (reg[rx] > reg[ry]) cmp_result = 1;
    else cmp_result = 2;

    pc++;
    return reg[rx];
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

    std::vector<uint16_t> reg(8, 0);
    std::vector<uint16_t> mem(256, 0);
    uint16_t cmp_result = 0;
    size_t pc = 0;
    int step = 0;

    while (pc < instructions.size()) {
        uint16_t instr = instructions[pc];
        bool is_branch = false;
        uint16_t result = emulate_instruction(instr, reg, mem, cmp_result, pc, is_branch);

        std::cout << "T=" << std::setw(2) << std::setfill('0') << step++
                  << " PC=" << std::setw(4) << std::hex << pc
                  << " INSTR=" << std::setw(4) << instr
                  << " REG[0]=" << reg[0]
                  << " CMP=" << cmp_result
                  << (is_branch ? " [BRANCH]" : "")
                  << std::endl;
    }

    return 0;
}
