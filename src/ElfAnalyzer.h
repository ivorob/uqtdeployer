#pragma once

#include <istream>

class ElfAnalyzer {
public:
    ElfAnalyzer(std::istream& input);
private:
    void invalidSignatureCauseException(uint8_t* signature);
    void invalidMachineClassCauseException(uint8_t classOfMachine);
};
