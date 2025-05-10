#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <iomanip>
#include <cstdint>

void error_exit(const std::string& msg) {
    std::cerr << "Error: " << msg << std::endl;
    std::exit(1);
}

uint16_t encode_instruction(const std::string& mnemonic) {
    static std::unordered_map<std::string, uint16_t> opcode_map = {
        {"ADD", 0}, {"SUB", 1}, {"XOR", 2}, {"AND", 3},
        {"SHL", 4}, {"SHR", 5}, {"OR", 6}, {"CLR", 7}
    };
    auto it = opcode_map.find(mnemonic);
    if (it == opcode_map.end()) error_exit("Unknown instruction: " + mnemonic);
    return it->second;
}

std::string decode_instruction(uint16_t instr) {
    static std::vector<std::string> mnemonics = {
        "ADD", "SUB", "XOR", "AND", "SHL", "SHR", "OR", "CLR"
    };
    uint16_t opcode = instr & 0x0007;
    if (opcode >= mnemonics.size()) return "UNKNOWN";
    return mnemonics[opcode];
}

void assemble(std::istream& in, std::ostream& out) {
    std::string line;
    while (std::getline(in, line)) {
        if (line.empty()) continue;
        std::istringstream iss(line);
        std::string mnemonic;
        iss >> mnemonic;
        uint16_t code = encode_instruction(mnemonic);
        out << std::hex << std::setw(4) << std::setfill('0') << code << std::endl;
    }
}

void disassemble(std::istream& in, std::ostream& out) {
    std::string line;
    while (std::getline(in, line)) {
        if (line.empty()) continue;
        uint16_t code;
        std::stringstream ss;
        ss << std::hex << line;
        ss >> code;
        out << decode_instruction(code) << std::endl;
    }
}

int main(int argc, char* argv[]) {
    std::string input_file, output_file;
    bool do_assemble = false, do_disassemble = false;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "-i" && i + 1 < argc) input_file = argv[++i];
        else if (arg == "-o" && i + 1 < argc) output_file = argv[++i];
        else if (arg == "-a") do_assemble = true;
        else if (arg == "-d") do_disassemble = true;
    }

    if (input_file.empty()) error_exit("Input file (-i) is required.");
    if (!do_assemble && !do_disassemble) error_exit("Either -a or -d must be specified.");

    std::ifstream in(input_file);
    if (!in) error_exit("Cannot open input file: " + input_file);

    if (!output_file.empty()) {
        std::ofstream out(output_file);
        if (!out) error_exit("Cannot open output file: " + output_file);
        if (do_assemble) assemble(in, out);
        else disassemble(in, out);
    } else {
        if (do_assemble) assemble(in, std::cout);
        else disassemble(in, std::cout);
    }

    return 0;
}
