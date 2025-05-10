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

uint16_t encode_instruction(const std::string& mnemonic, uint16_t imm = 0, uint16_t rx = 0, uint16_t ry = 0) {
    static std::unordered_map<std::string, uint16_t> opcode_map = {
        {"ADD", 0}, {"SUB", 1}, {"XOR", 2}, {"AND", 3},
        {"SHL", 4}, {"SHR", 5}, {"OR", 6}, {"CLR", 7},
        {"BIE", 0}, {"BIG", 1}, {"BIL", 2},
        {"LD", 0}, {"ST", 1}
    };

    if (mnemonic == "BIE" || mnemonic == "BIG" || mnemonic == "BIL") {
        uint16_t cond = opcode_map[mnemonic];     // cond in bits [3:2]
        return (imm << 4) | (cond << 2) | 0b10;    // format = 10
    }

    if (mnemonic == "LD" || mnemonic == "ST") {
        uint16_t is_store = (mnemonic == "ST") ? 1 : 0;
        return (rx << 13) | (ry << 10) | (is_store << 2) | 0b11;
    }

    auto it = opcode_map.find(mnemonic);
    if (it == opcode_map.end()) error_exit("Unknown instruction: " + mnemonic);
    return (rx << 13) | (ry << 10) | it->second;
}

std::string decode_instruction(uint16_t instr) {
    uint16_t format = instr & 0x0003;
    if (format == 0b10) {
        uint16_t cond = (instr >> 2) & 0x3;
        uint16_t imm = instr >> 4;
        std::string mnemonic = (cond == 0 ? "BIE" : cond == 1 ? "BIG" : cond == 2 ? "BIL" : "???");
        std::ostringstream oss;
        oss << mnemonic << " " << imm;
        return oss.str();
    }

    if (format == 0b11) {
        uint16_t is_store = (instr >> 2) & 0x1;
        uint16_t rx = (instr >> 13) & 0x7;
        uint16_t ry = (instr >> 10) & 0x7;
        std::ostringstream oss;
        oss << (is_store ? "ST" : "LD") << " R" << rx << ", (R" << ry << ")";
        return oss.str();
    }

    static std::vector<std::string> mnemonics = {
        "ADD", "SUB", "XOR", "AND", "SHL", "SHR", "OR", "CLR"
    };
    uint16_t opcode = instr & 0x0007;
    uint16_t rx = (instr >> 13) & 0x7;
    uint16_t ry = (instr >> 10) & 0x7;
    if (opcode >= mnemonics.size()) return "UNKNOWN";
    std::ostringstream oss;
    oss << mnemonics[opcode] << " R" << rx << ", R" << ry;
    return oss.str();
}

void assemble(std::istream& in, std::ostream& out) {
    std::string line;
    while (std::getline(in, line)) {
        if (line.empty()) continue;
        std::istringstream iss(line);
        std::string mnemonic;
        std::string rxtok, rytok;
        uint16_t imm = 0, rx = 0, ry = 0;
        iss >> mnemonic;

        if (mnemonic == "BIE" || mnemonic == "BIG" || mnemonic == "BIL") {
            iss >> imm;
        } else if (mnemonic == "LD" || mnemonic == "ST") {
            iss >> rxtok >> rytok;
            if (rxtok[0] == 'R') rx = std::stoi(rxtok.substr(1));
            if (rytock[0] == '(') ry = std::stoi(rytok.substr(2, rytok.length() - 3));
        } else {
            iss >> rxtok >> rytok;
            if (rxtok[0] == 'R') rx = std::stoi(rxtok.substr(1));
            if (rytok[0] == 'R') ry = std::stoi(rytok.substr(1));
        }

        uint16_t code = encode_instruction(mnemonic, imm, rx, ry);
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
