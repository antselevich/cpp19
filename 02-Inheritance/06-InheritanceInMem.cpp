#include <iostream>

struct Base {
    int baseField;
    char baseField2;
    // short baseField2;
};

struct Derived : public Base {
    int derivedField;
};

int main() {
    Derived d;

    std::cout <<
        "&d.baseField   : " << &d.baseField << std::endl <<
        "&d.baseField2  : " << &d.baseField2 << std::endl <<
        "&d.derivedField: " << &d.derivedField << std::endl;

    return 0;
}
