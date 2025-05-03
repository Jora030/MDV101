#include "BittyInstructionGenerator.h"
#include <random>

uint16_t BittyInstructionGenerator::Generate() {
    static std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<uint16_t> opcode(0, 5);
    std::uniform_int_distribution<uint16_t> reg(0, 7);
    std::uniform_int_distribution<uint16_t> imm(0, 15);

    uint16_t op = opcode(rng);
    uint16_t rd = reg(rng);
    uint16_t rs1 = reg(rng);
    uint16_t rs2 = reg(rng);

    if (op == 0xF) {
        return (0xF << 12) | (rd << 8) | imm;
    }

    return (op << 12) | (rd << 8) | (rs1 << 4) | rs2;
}
