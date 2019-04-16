#include <iostream>

void Func(...) {
    std::cout << "Func(...)" << std::endl;
}
void Func(int a, int b) {
    std::cout << "Func(int, int)" << std::endl;
}

int main() {
    Func(1.0, 1.0);
    Func("a", 1.0);

    return 0;
}