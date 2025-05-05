#include "bitty_emu.h"

BittyEmulator::BittyEmulator() {
    registers_.resize(8, 0); 
}

uint16_t BittyEmulator::Evaluate(uint16_t instruction) {
    uint16_t opcode = (instruction >> 12) & 0xF;
    uint16_t rd = (instruction >> 8) & 0xF;
    uint16_t rs1 = (instruction >> 4) & 0xF;
    uint16_t rs2 = instruction & 0xF;

    switch (opcode) {
        case 0x0:
            registers_[rd] = registers_[rs1] + registers_[rs2];
            break;
        case 0x1:
            registers_[rd] = registers_[rs1] - registers_[rs2];
            break;
        case 0x2:
            registers_[rd] = registers_[rs1] & registers_[rs2];
            break;
        case 0x3:
            registers_[rd] = registers_[rs1] | registers_[rs2];
            break;
        case 0x4:
            registers_[rd] = registers_[rs1] ^ registers_[rs2];
            break;
        case 0xF:
            registers_[rd] = rs2;
            break;
        default:
            break;
    }

    return registers_[rd];
}

uint16_t BittyEmulator::GetRegisterValue(uint16_t reg_num) const {
    if (reg_num < registers_.size())
        return registers_[reg_num];
    return 0;
}
