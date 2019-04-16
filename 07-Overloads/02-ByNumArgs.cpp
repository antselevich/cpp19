#include <iostream>

void Foo(int a) {
    std::cout << "Foo(int)" << std::endl;
}
void Foo(int a, int b) {
    std::cout << "Foo(int, int)" << std::endl;
}

void Bar(float a, int b) {
    std::cout << "Bar(float, int)" << std::endl;
}
void Bar(int a, float b) {
    std::cout << "Bar(int, float)" << std::endl;
}

struct Double {
    Double(double a) {}
};

void Conv(int a, Double b) {
    std::cout << "Conv(int, Double)" << std::endl;
}
void Conv(Double a, int b) {
    std::cout << "Conv(Double, int)" << std::endl;
}

class Father {};
class Son : public Father {};

struct ToSon {
    ToSon(Son) {}
};

void Inh(int a, const Father& obj2) {
    std::cout << "Inh(int, const Father&)" << std::endl;
}
void Inh(float a, ToSon ts) {
    std::cout << "Inh(float, ToSon)" << std::endl;
}

int main() {
    Foo(1.0);
    Foo(1.0, 1.0);

    // Bar(1.0, 1.0);

    // Conv(1.0, 1.0);

    // Inh(1.0, Son {});

    return 0;
}