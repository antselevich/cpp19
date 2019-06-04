#include <iostream>
#include <functional>
#include <string>

std::string Func(int a, int b, int c) {
    return
        "a: " + std::to_string(a) +
        ", b: " + std::to_string(b) +
        ", c: " + std::to_string(c);
}

int main() {
    using namespace std::placeholders;

    std::function<std::string(int, int)> f1 = std::bind(Func, _1, _2, 5);
    std::cout << "f1(1, 2)  " << f1(1, 2) << std::endl;
    f1 = std::bind(Func, _1, 5, _2);
    std::cout << "f1(1, 2)  " << f1(1, 2) << std::endl;
    f1 = std::bind(Func, _2, _1, 5);
    std::cout << "f1(1, 2)  " << f1(1, 2) << std::endl;
    f1 = std::bind(Func, _2, _1, _2);
    std::cout << "f1(1, 2)  " << f1(1, 2) << std::endl;
}
