#include <gtest/gtest.h>
#include <sstream>

#include "ElfAnalyzer.h"

TEST(ElfAnalyzerTest, cannot_open_invalid_elf_file) {
    // Arrange
    std::istringstream input("ELF");

    // Act
    bool hasException = [&input]() -> bool {
        try {
            ElfAnalyzer elfAnalyzer(input);
            return false;
        } catch (...) {
            return true;
        }
    }();

    // Assert
    ASSERT_TRUE(hasException);
}
