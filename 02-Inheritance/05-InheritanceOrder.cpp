#include <iostream>

class BaseField {
public:
    BaseField() {
        std::cout << "BaseField constructor" << std::endl;
    }
};

class DerivedField {
public:
    DerivedField(const char* y) {
        std::cout << "DerivedField constructor: " << y << std::endl;
    }
};

class Base {
public:
    Base(int x) {
        std::cout << "Base constructor: " << x << std::endl;
    }
private:
    BaseField baseField;
};

class Derived : public Base {
public:
    Derived(): Base(42), derivedField("ololo") {
        std::cout << "Derived constructor" << std::endl;
    }
private:
    DerivedField derivedField;
};

int main() {
    Derived d;
    // Base b(100500);
    return 0;
}
