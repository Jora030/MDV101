#ifndef BITTY_EMU_H
#define BITTY_EMU_H

#include <vector>
#include <cstdint>

class BittyEmulator {
public:
    BittyEmulator();
    uint16_t Evaluate(uint16_t instruction);
    uint16_t GetRegisterValue(uint16_t reg_num) const;

private:
    std::vector<uint16_t> registers_;
};

#endif
