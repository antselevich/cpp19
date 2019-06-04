#include <algorithm>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

std::string_view getString() {
    return std::string("Hello world");
}

int main() {
    std::vector<std::string> elems;
    elems.reserve(1 << 15);
    for (size_t i = 0; i < (1 << 16); ++i) {
        elems.push_back("id" + std::to_string(i));
        elems.push_back("ID" + std::to_string(i));
    }

    // std::sort(elems.begin(), elems.end(),
    //     [] (const auto& a, const auto& b) {
    //         return a.substr(2) < b.substr(2);
    //     });

    std::sort(elems.begin(), elems.end(),
        [] (const auto& a, const auto& b) {
            return std::string_view(a).substr(2) < std::string_view(b).substr(2);
        });

    size_t i = 0;
    for (auto&& elem : elems) {
        if (++i > 10) break;
        std::cout << elem << ", ";
    }
    std::cout << std::endl;

    // // Bang
    // std::cout << getString() << std::endl;
}
