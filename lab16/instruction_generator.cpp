#include <iostream>
#include <fstream>
#include <random>
#include <iomanip>
#include <cstdlib>

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
    std::uniform_int_distribution<uint16_t> dist(0, 0xFFFF);

    for (int i = 0; i < N; ++i) {
        uint16_t instr = dist(gen);
        out << std::hex << std::setw(4) << std::setfill('0') << instr << std::endl;
    }

    std::cout << "Generated " << N << " instructions in prog.hex\n";
    return 0;
}
