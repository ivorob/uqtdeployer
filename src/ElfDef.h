#pragma once

#define ELF_SIGNATURE_BYTE0     0x7f
#define ELF_SIGNATURE_BYTE1     'E'
#define ELF_SIGNATURE_BYTE2     'L'
#define ELF_SIGNATURE_BYTE3     'F'
#define ELF_SIGNATURE_SIZE      4

#define ELF_MACHINE_CLASS_NONE  0
#define ELF_MACHINE_CLASS_32BIT 1
#define ELF_MACHINE_CLASS_64BIT 2

struct ElfHeader {
    uint8_t signature[ELF_SIGNATURE_SIZE];
    uint8_t classOfMachine;
    uint8_t dataFormat;
};
