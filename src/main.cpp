#include <iostream>

#include "GPU_Disasm.h"
#include <vector>
#include <filesystem>
#include <fstream>
#include <format>


namespace fs = std::filesystem;

inline void ignoreLine() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void dump_disasm_to_file(const fs::path& path, const std::vector<GPUDebugOp>& disassembled) {
    std::ofstream outfile(path, std::ios::binary);
    if (!outfile) {
        std::cout << "Cannot access the file " << path << "\n";
        return;
    }

    uint32_t offset = 0;
    for (const auto& line: disassembled) {
        auto output_start = std::format("{:08X}  ", offset);
        outfile << output_start << line.desc << "\n";
        offset += 4;
    }
}

void run_tests() {
    GPU_Disasm disasm;

    const std::vector<uint8_t> data = {
            0xC0, 0x3D, 0xAF, 0x08, 0x01, 0x00, 0x00, 0xD2, 0x00, 0x02, 0x00, 0x9D, 0x00, 0x40, 0x04, 0x9C,
            0x00, 0x00, 0x00, 0xD4, 0xDF, 0x3D, 0x04, 0xD5, 0x00, 0x00, 0x00, 0x15, 0xDF, 0x3D, 0x04, 0x16,
            0x00, 0x00, 0x00, 0xD4, 0xDF, 0x3D, 0x04, 0xD5, 0x00, 0x00, 0x00, 0x15, 0xDF, 0x3D, 0x04, 0x16,
            0x00, 0x70, 0x43, 0x42
    };

    auto vector_test = disasm.DisassembleOpcodeRange(data);

    auto example = vector_test[0].desc;

    u32 opcode_data = 0x08'af'3d'c0;
    auto opcode_test = disasm.DisassembleOpcode(opcode_data, 0);
    if (opcode_test.desc != example) {
        std::cout << "Mismatch!\n";
    } else {
        std::cout << "Correct! It's " << example << "\n";
    }

    std::cout << "Done!\n";
}

void disassemble_file(const fs::path& path, const fs::path& save_to) {
    std::ifstream infile(path, std::ios::binary | std::ios::ate);
    if (!infile) {
        std::cout << "Cannot open the file " << path << "\n";
        return;
    }

    auto size = infile.tellg();
    auto remainder = size % 4;
    if (remainder) {
        std::cout << "The file size is not divisible by 4 - trimming..." << "\n";
        size -= remainder;
    }

    std::vector<uint8_t> data;
    data.resize(size);

    infile.seekg(0);
    infile.read(reinterpret_cast<char*>(data.data()), size);

    GPU_Disasm disasm;
    auto results = disasm.DisassembleOpcodeRange(data);

    dump_disasm_to_file(save_to, results);
}

int main() {
    // run_tests();
    std::string line; // buffer

    fs::path file_path;

    std::cout << "Enter the path to the input file\n";
    // ignoreLine();
    std::getline(std::cin, line);
    file_path = line;

    fs::path destination_path;

    std::cout << "Enter the path the disassembled data will be written to\n";
    // ignoreLine();
    std::getline(std::cin, line);
    destination_path = line;

    disassemble_file(file_path, destination_path);

    return 0;
}
