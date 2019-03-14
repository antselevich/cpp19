#include <iostream>

int main() {
    int val = 3;
    int val2 = 4;
    const int* a = &val; // <=> int const* a = &val;
    std::cout << val << ", " << *a << std::endl;
    // *a = 4;
    a = &val2;
    std::cout << *a << std::endl;

    int* const b = &val;
    *b = 5;
    std::cout << val << ", " << *b << std::endl;
    // b = &val2;

    const int& c = val; // <=> int const& c = val;
    std::cout << val << ", " << c << std::endl;
    // c = 6;

    // int& const d = val;

    return 0;
}
