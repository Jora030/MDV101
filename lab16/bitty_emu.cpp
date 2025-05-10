#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <sstream>
#include <iomanip>

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

    for (size_t i = 0; i < instructions.size(); ++i) {
        uint16_t instr = instructions[i];
        std::cout << "PC=" << std::setw(4) << std::setfill('0') << std::hex << i
                  << "  INSTR=" << std::setw(4) << instr
                  << "  REG_before=" << std::setw(4) << reg;

        reg = emulate_instruction(instr, reg);

        std::cout << "  REG_after=" << std::setw(4) << reg << std::endl;
    }

    return 0;
}
