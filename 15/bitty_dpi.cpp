#include <iostream>
#include "bitty_emu.h"

extern "C" void bitty_check(uint16_t instruction, uint16_t hardware_result) {
    static BittyEmulator emulator;
    uint16_t result = emulator.Evaluate(instruction);

    if (result != hardware_result) {
        std::cerr << "[DPI ERROR] Mismatch:\n";
        std::cerr << "  Instruction: 0x" << std::hex << instruction << "\n";
        std::cerr << "  Hardware result: 0x" << std::hex << hardware_result << "\n";
        std::cerr << "  Emulator result: 0x" << std::hex << result << "\n";
        exit(1);
    } else {
        std::cout << "[DPI] OK: instruction 0x" << std::hex << instruction << std::endl;
    }
}