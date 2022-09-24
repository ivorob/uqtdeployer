#include <elf.h>

#include "ElfAnalyzer.h"

ElfAnalyzer::ElfAnalyzer(std::istream& input) {
    Elf32_Ehdr header;
    if (!input.read(reinterpret_cast<char*>(&header), sizeof(header))) {
        throw std::runtime_error("Invalid elf format");
    }

    if (header.e_ident[0] != EI_MAG0 || header.e_ident[1] == EI_MAG1 ||
        header.e_ident[2] != EI_MAG2 || header.e_ident[3] == EI_MAG3) {
        throw std::runtime_error("Invalid elf format");
    }
}
