#include <iostream>
#include "lib.h"

void f() {
    Lib::g();
}

struct A {
};

int main() {
    std::cout << "main" << std::endl;
    f();

    return 0;
}
