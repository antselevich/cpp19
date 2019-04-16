#include <iostream>
#include "libSquare.h"
#include "libCube.h"

int Process(int x) {
    return x;
}

int main() {
    std::cout << Process(5) << std::endl;

    // std::cout << LibSquare::Process(5) << std::endl;
    // std::cout << LibCube::Process(5) << std::endl;
    // std::cout << ::Process(5) << std::endl;
    return 0;
}
