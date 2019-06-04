#include <iostream>

template <class T>
size_t sizeOf();

template <>
size_t sizeOf<int>() {
    return 4;
}

template <>
size_t sizeOf<double>() {
    return 8;
}

int main() {
    // Won't compile
    // std::cout << sizeOf() << std::endl;

    std::cout << sizeOf<int>() << std::endl;
    std::cout << sizeOf<double>() << std::endl;

    // Won't compile
    // std::cout << sizeOf<std::string>() << std::endl;
    // std::cout << sizeOf<float>() << std::endl;
    return 0;
}
