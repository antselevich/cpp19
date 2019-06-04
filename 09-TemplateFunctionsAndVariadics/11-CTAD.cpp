#include <iostream>

template <class T>
class A {
public:
    A(T value_) : value(value_) {}

    void PrintValueType() const {
        std::cout << typeid(value).name() << std::endl;
    }

private:
    T value;
};

int main() {
    std::pair p(1, 2.f);
    std::cout << typeid(p.first).name() << ", "
              << typeid(p.second).name() << std::endl;

    auto af = new A(1.2f);
    af->PrintValueType();
    delete af;

    auto as = new A(std::string("abc"));
    as->PrintValueType();
    delete as;

    return 0;
}
