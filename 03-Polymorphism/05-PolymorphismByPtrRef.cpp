#include <iostream>

class Base {
public:
    virtual ~Base() {}

    virtual void Do() const {
        std::cout << "Base::Do" << std::endl;
    }

private:
    uint64_t x;
};

class Derived : public Base {
public:
    void Do() const override final {
        std::cout << "Derived::Do" << std::endl;
    }

private:
    uint64_t y;
};

int main() {
    Derived d;
    std::cout << "sizeof derived object: " << sizeof(d) << std::endl;

    // Base b = d;
    // std::cout << "sizeof base object: " << sizeof(b) << std::endl;
    // b.Do();

    Base& bRef = d;
    std::cout << "sizeof base ref to derived object: "
              << sizeof(bRef) << std::endl;
    bRef.Do();

    Base* bPtr = &d;
    std::cout << "sizeof base ptr to derived object "
              << sizeof(*bPtr) << std::endl;
    bPtr->Do();

    return 0;
}
