#include "lib.h"

namespace {
void f() {
    std::cout << "lib f" << std::endl;
}
} // unnamed namespace

void Lib::g() {
    std::cout << "g" << std::endl;
    f();
}
