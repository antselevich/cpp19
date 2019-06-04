#include <iostream>
#include <functional>

struct Add {
    int operator()(int b) const {
        return a + b;
    }
    int a;
};
struct Mul {
    int operator()(int b) const {
        return a * b;
    }
    int a;
};

int main() {
    Add add{2};
    Mul mul{2};
    std::cout << "add(3): " << add(3) << std::endl;
    std::cout << "mul(3): " << mul(3) << std::endl;

    std::function<int(int)> f = add;
    std::cout << "f(3): " << f(3) << std::endl;
    f = mul;
    std::cout << "f(3): " << f(3) << std::endl;

    return 0;
}