#include <iostream>
#include <cassert>
#include "bitty_emu.h"

int main() {
    BittyEmulator emu;

    // Загрузка значений
    // LDI R0 <- 5
    emu.Evaluate(0xF005);
    assert(emu.GetRegisterValue(0) == 5);
    std::cout << "Test LDI R0 passed.\n";

    // LDI R1 <- 10
    emu.Evaluate(0xF10A);
    assert(emu.GetRegisterValue(1) == 10);
    std::cout << "Test LDI R1 passed.\n";

    // Сложение
    // ADD R2 = R0 + R1 → 5 + 10 = 15
    emu.Evaluate(0x0210);  // opcode=0 (ADD), rd=2, rs1=1, rs2=0
    assert(emu.GetRegisterValue(2) == 15);
    std::cout << "Test ADD passed.\n";

    // Вычитание
    // SUB R3 = R1 - R0 → 10 - 5 = 5
    emu.Evaluate(0x1310);  // opcode=1 (SUB), rd=3, rs1=1, rs2=0
    assert(emu.GetRegisterValue(3) == 5);
    std::cout << "Test SUB passed.\n";

    // AND
    // R4 = R0 & R1 = 5 & 10 = 0
    emu.Evaluate(0x2410);
    assert(emu.GetRegisterValue(4) == (5 & 10));
    std::cout << "Test AND passed.\n";

    // OR
    // R5 = R0 | R1 = 5 | 10 = 15
    emu.Evaluate(0x3510);
    assert(emu.GetRegisterValue(5) == (5 | 10));
    std::cout << "Test OR passed.\n";

    // XOR
    // R6 = R0 ^ R1 = 5 ^ 10 = 15
    emu.Evaluate(0x4610);
    assert(emu.GetRegisterValue(6) == (5 ^ 10));
    std::cout << "Test XOR passed.\n";

    std::cout << "\n All tests passed successfully!" << std::endl;
    return 0;
}
