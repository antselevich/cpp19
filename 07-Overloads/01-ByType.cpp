#include <iostream>

struct Int {
    Int(int a) {}
};

class GrandFather {};
class Father : public GrandFather {};
class Mom {};
class Son : public Father, public Mom {};

struct ToSon {
    ToSon(const Son&) {}
};

void Func(int x) {
    std::cout << "Func(int)" << std::endl;
}
void Func(float x) {
    std::cout << "Func(float)" << std::endl;
}
void Func(Int x) {
    std::cout << "Func(Int)" << std::endl;
}
void Func(const char* x) {
    std::cout << "Func(const char*)" << std::endl;
}
void Func(const GrandFather& obj) {
    std::cout << "Func(GrandFather)" << std::endl;
}
void Func(ToSon obj) {
    std::cout << "Func(ToSon)" << std::endl;
}
void Func(const Father& obj) {
    std::cout << "Func(Father)" << std::endl;
}
// void Func(const Mom& obj) {
//     std::cout << "Func(Mom)" << std::endl;
// }

int main() {
    Func(1);
    // Func(1.0);
    // Func(0);

    // Func(Father {});
    Func(Son {});
    return 0;
}
