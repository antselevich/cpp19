#include <iostream>

class Base {
public:
    Base(): x(2), y(4), z(6) {}
    int x;
protected:
    int y;
private:
    int z;
};

class Derived : public Base {
public:
    int GetBaseField() const {
        return x;
    }
};

class DerivedFromDerived : public Derived {
public:
    int GetBaseField() const {
        return y;
    }
};

int main() {
    Derived d;
    std::cout << d.x << std::endl;
    std::cout << d.GetBaseField() << std::endl;

    DerivedFromDerived dd;
    // std::cout << dd.y << std::endl;
    std::cout << dd.GetBaseField() << std::endl;

    return 0;
}
