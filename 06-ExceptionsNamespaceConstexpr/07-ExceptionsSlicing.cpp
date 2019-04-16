#include <iostream>

struct A {
    virtual ~A() = default;
    virtual int getX() const {
        return 0;
    }
};

struct B : public A {
    B(int _x) : x(_x) {}

    int getX() const override final {
        return x;
    }
    int x;
};


int main() {
    try {
        throw B(5);
    } catch (A a) {
        std::cout << a.getX() << std::endl;
    }

    return 0;
}
