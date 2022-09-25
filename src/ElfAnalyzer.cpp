#include "ElfAnalyzer.h"
#include "ElfDef.h"

ElfAnalyzer::ElfAnalyzer(std::istream& input) {
    ElfHeader header;
    if (!input.read(reinterpret_cast<char*>(&header), sizeof(header))) {
        throw std::runtime_error("Invalid elf format");
    }

    invalidSignatureCauseException(header.signature);
    invalidMachineClassCauseException(header.classOfMachine);
}

void ElfAnalyzer::invalidSignatureCauseException(uint8_t* signature) {
    if (signature[0] != ELF_SIGNATURE_BYTE0 || signature[1] != ELF_SIGNATURE_BYTE1 ||
        signature[2] != ELF_SIGNATURE_BYTE2 || signature[3] != ELF_SIGNATURE_BYTE3) {
        throw std::runtime_error("Invalid signature");
    }
}

void ElfAnalyzer::invalidMachineClassCauseException(uint8_t classOfMachine) {
    switch (classOfMachine) {
        case ELF_MACHINE_CLASS_32BIT:
        case ELF_MACHINE_CLASS_64BIT:
            break;
        case ELF_MACHINE_CLASS_NONE:
        default:
            throw std::runtime_error("Invalid class of machine");
            break;
    }
}
