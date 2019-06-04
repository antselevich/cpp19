#include <iostream>
#include <filesystem>

int main() {
    namespace fs = std::filesystem;

    std::string name;
    std::cin >> name;

    switch (fs::path p(name); fs::status(p).type()) {
    case fs::file_type::regular:
        std::cout << p.string() << " " << fs::file_size(p) << std::endl;
        break;
    case fs::file_type::directory:
        std::cout << p.string() << ":" << std::endl;
        for (auto&& e : fs::directory_iterator(p)) {
            std::cout << " " << e.path().string() << std::endl;
        }
        break;
    default:
        std::cout << "Unknown type" << std::endl;
    }

    return 0;
}
