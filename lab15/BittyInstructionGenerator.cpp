#include <cstdint>
#include <cstdlib>
#include <ctime>


extern "C" void init_generator() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}


extern "C" uint32_t get_instruction() {
    uint16_t opcode = std::rand() % 6; 
    uint16_t rd = std::rand() % 8;
    uint16_t rs1 = std::rand() % 8;
    uint16_t rs2 = std::rand() % 8;

    uint16_t instr = 0;

    if (opcode == 5) {
        instr = (0xF << 12) | (rd << 8) | (0x0 << 4) | (std::rand() % 16);
    } else {
        instr = (opcode << 12) | (rd << 8) | (rs1 << 4) | rs2;
    }

    return static_cast<uint32_t>(instr);
}
