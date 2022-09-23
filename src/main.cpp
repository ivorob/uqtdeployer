#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

namespace {

void usage() {
    std::cout << "Usage:" << std::endl
              << "\tuqtdeployer executable" << std::endl;
}

}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        usage();
        return EXIT_FAILURE;
    }

    try {
        std::string filename = argv[1];
        if (!fs::exists(filename)) {
            throw std::runtime_error("File '" + filename + "' isn't exists");
        }

        std::cout << "Handling file '" + filename + "'...\tOK" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return EXIT_SUCCESS;
}
