#include <iostream>

#include "unit1.h"
#include "unit2.h"

int main() {
    Set1Var(10);
    std::cout << "Get1Var " << Get1Var() << std::endl;
    std::cout << "Get2Var " << Get2Var() << std::endl;
    Set2Var(20);
    std::cout << "Get1Var " << Get1Var() << std::endl;
    std::cout << "Get2Var " << Get2Var() << std::endl;

    std::cout << "Get1Addr " << Get1Addr() << std::endl;
    std::cout << "Get2Addr " << Get2Addr() << std::endl;

    return 0;
}
