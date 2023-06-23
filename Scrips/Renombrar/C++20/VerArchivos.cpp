#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    std::string relativePath = "../C++20";

    for (const auto& entry : fs::directory_iterator(relativePath)) {
        if (entry.is_regular_file()) {
            std::cout << entry.path().filename().string() << std::endl;
        }
    }

    return 0;
}
