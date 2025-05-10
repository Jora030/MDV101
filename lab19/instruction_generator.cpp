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
    std::uniform_int_distribution<int> type_dist(0, 11); // 0–7 ALU, 8–10 branch, 11=mem
    std::uniform_int_distribution<uint16_t> reg_dist(0, 7);
    std::uniform_int_distribution<uint16_t> imm_dist(0, 255);

    for (int i = 0; i < N; ++i) {
        uint16_t instr;
        int type = type_dist(gen);

        if (type < 8) {
            // ALU
            uint16_t rx = reg_dist(gen);
            uint16_t ry = reg_dist(gen);
            uint16_t opcode = type;
            instr = (rx << 13) | (ry << 10) | opcode;
        } else if (type < 11) {
            // Branch
            uint16_t cond = type - 8;
            uint16_t imm = imm_dist(gen);
            instr = (imm << 4) | (cond << 2) | 0b10;
        } else {
            // Memory: ld or st
            uint16_t rx = reg_dist(gen);
            uint16_t ry = reg_dist(gen);
            bool is_store = gen() % 2;
            instr = (rx << 13) | (ry << 10) | ((is_store ? 1 : 0) << 2) | 0b11;
        }

        out << std::hex << std::setw(4) << std::setfill('0') << instr << std::endl;
    }

    std::cout << "Generated " << N << " instructions in prog.hex\n";
    return 0;
}
