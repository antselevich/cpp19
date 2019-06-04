#include <iostream>
#include <typeinfo>

int main() {
    auto x = 5;
    std::cout << typeid(x).name() << std::endl;

    auto* y1 = &x;
    auto  y2 = &x;
    std::cout << y1 << " " << typeid(y1).name() << std::endl;
    std::cout << y2 << " " << typeid(y2).name() << std::endl;

    int addr = 0xDEADBEEF;
    auto* y3 = &x, y4 = addr;

    // The only case when auto and auto* differ
    // auto  y3 = &x, y4 = addr;

    std::cout << y3 << " " << typeid(y3).name() << std::endl;
    std::cout << y4 << " " << typeid(y4).name() << std::endl;

    return 0;
}
