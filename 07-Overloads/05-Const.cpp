#include <iostream>

struct Foo {
    Foo(int field) : Field(field) {}
    int Get() const {
        std::cout << "Get() const" << std::endl;
        return Field;
    }
    int& Get() {
        std::cout << "Get()" << std::endl;
        return Field;
    }
    int Field;
};

int main() {
    const Foo a(1);
    std::cout << a.Get() << std::endl;
    Foo b(1);
    std::cout << b.Get() << std::endl;
    b.Get() = 3;

    return 0;
}