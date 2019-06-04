#include <iostream>
#include <functional>

int Add(int a, int b) {
    return a + b;
}
int Mul(int a, int b) {
    return a * b;
}
int Sub(int a) {
    return -a;
}
int Sub(int a, int b) {
    return a - b;
}

using BinInt = int (*)(int, int);
// typedef int (*BinInt)(int, int);

int main() {
    BinInt fptr = Add;
    std::cout << "fptr(2, 3): " << fptr(2, 3) << std::endl;
    fptr = &Mul;
    std::cout << "fptr(2, 3): " << (*fptr)(2, 3) << std::endl;
    fptr = Sub;
    std::cout << "fptr(2, 3): " << (*fptr)(2, 3) << std::endl;

    std::function<int(int, int)> func = Add;
    std::cout << "func(2, 3): " << func(2, 3) << std::endl;
    func = &Mul;
    std::cout << "func(2, 3): " << func(2, 3) << std::endl;
    // func = Sub;
    func = static_cast<int(*)(int, int)>(Sub);
    std::cout << "func(2, 3): " << func(2, 3) << std::endl;
    return 0;
}