#include <iostream>

void boom() {
    std::cout << "boom before throw" << std::endl;
    throw 42;
    std::cout << "boom after throw" << std::endl;
}

void f() {
    std::cout << "f before boom call" << std::endl;
    boom();
    std::cout << "f after boom call" << std::endl;
}

void g() {
    std::cout << "g before f call" << std::endl;
    try {
        std::cout << "try before f call" << std::endl;
        f();
        std::cout << "try after f call" << std::endl;
    } catch (int x) {
        std::cout << "g: catch " << x << std::endl;
        throw;
    }
    std::cout << "g after f call" << std::endl;
}

int main() {
    std::cout << "main before g call" << std::endl;
    try {
        std::cout << "try before g call" << std::endl;
        g();
        std::cout << "try after g call" << std::endl;
    } catch (int x) {
    // } catch (...) {
        std::cout << "main: catch " << x << std::endl;
        // std::cout << "catch smth" << std::endl;
    }
    std::cout << "main after g call" << std::endl;
    return 0;
}
