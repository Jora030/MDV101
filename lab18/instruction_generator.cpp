#include <iostream>
#include <fstream>
#include <random>
#include <iomanip>
#include <string>
#include <cstdint>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <num_instructions>\n";
        return 1;
    }

    int N = std::atoi(argv[1]);
    if (N <= 0) {
        std::cerr << "Number of instructions must be positive.\n";
        return 1;
    }

    std::ofstream out("prog.hex");
    if (!out) {
        std::cerr << "Failed to open prog.hex for writing.\n";
        return 1;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> instr_type(0, 9);
    std::uniform_int_distribution<uint16_t> imm_dist(0, 255);

    for (int i = 0; i < N; ++i) {
        uint16_t instr;
        int choice = instr_type(gen);

        if (choice < 8) {
            instr = static_cast<uint16_t>(choice);
        } else {
            uint16_t cond = choice - 8;
            uint16_t imm = imm_dist(gen);
            instr = (imm << 4) | (cond << 2) | 0b10;
        }

        out << std::hex << std::setw(4) << std::setfill('0') << instr << std::endl;
    }

    std::cout << "Generated " << N << " instructions in prog.hex\n";
    return 0;
}
