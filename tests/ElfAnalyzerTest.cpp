#include <gtest/gtest.h>
#include <sstream>

#include "ElfAnalyzer.h"
#include "ElfDef.h"

TEST(ElfAnalyzerTest, cannot_open_invalid_elf_file) {
    // Arrange
    std::istringstream input("ELF");

    // Act
    std::string exception;
    bool hasException = [&input, &exception]() -> bool {
        try {
            ElfAnalyzer elfAnalyzer(input);
            return false;
        } catch (const std::exception& e){
            exception = e.what();
            return true;
        }
    }();

    // Assert
    ASSERT_TRUE(hasException);
    ASSERT_EQ("Invalid elf format", exception);
}

TEST(ElfAnalyzerTest, invalid_machine_class_cause_exception) {
    // Arrange
    std::string elfFile;
    elfFile.push_back(ELF_SIGNATURE_BYTE0);
    elfFile.push_back(ELF_SIGNATURE_BYTE1);
    elfFile.push_back(ELF_SIGNATURE_BYTE2);
    elfFile.push_back(ELF_SIGNATURE_BYTE3);
    elfFile.push_back(0);
    elfFile.push_back(0);
    std::istringstream input(elfFile);

    // Act
    std::string exception;
    bool hasException = [&input, &exception]() -> bool {
        try {
            ElfAnalyzer elfAnalyzer(input);
            return false;
        } catch (const std::exception& e) {
            exception = e.what();
            return true;
        }
    }();

    // Assert
    ASSERT_TRUE(hasException);
    ASSERT_EQ("Invalid class of machine", exception);
}
