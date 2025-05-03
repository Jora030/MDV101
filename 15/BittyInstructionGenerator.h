#ifndef BITTY_INSTRUCTION_GENERATOR_H
#define BITTY_INSTRUCTION_GENERATOR_H

#include <cstdint>

class BittyInstructionGenerator {
public:
    BittyInstructionGenerator() = default;
    uint16_t Generate();
};

#endif
