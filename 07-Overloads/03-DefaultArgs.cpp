#include <iostream>

void Func(int a = 1, int b = 2) {
    std::cout << "Func(int, int)" << std::endl;
}
void Func() {
    std::cout << "Func()" << std::endl;
}
void Func(float a) {
    std::cout << "Func(float)" << std::endl;
}
void Func(float a, float b) {
    std::cout << "Func(float, float)" << std::endl;
}

int main() {
    Func();
    Func(1.0);
    Func(1.0, 1.0);

    return 0;
}