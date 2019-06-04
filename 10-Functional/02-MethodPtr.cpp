#include <iostream>
#include <functional>
#include <string>

struct Base {
    int a;

    Base(int _a) : a(_a) {}

    int Add(int b) const {
        return a + b;
    }
    int Mul(int b) const {
        return a * b;
    }

    std::string Action() {
        return "Base::Action";
    }
    virtual std::string VAction() {
        return "Base::VAction";
    }
};
struct Child : public Base {
    Child(int _a) : Base(_a) {}

    std::string Action() {
        return "Child::Action";
    }
    std::string VAction() override {
        return "Child::VAction";
    }
};

using UnIntPtr = int (Base::*)(int)const;
// typedef int (Base::*UnIntPtr)(int)const;
using NoArgPtr = std::string (Base::*)();

int main() {
    UnIntPtr mptr = &Base::Add;
    Base f1(2);
    Base* f2 = new Base(3);
    std::cout << "mptr(f1, 3): " << (f1.*mptr)(3) << std::endl;
    std::cout << "mptr(f2, 3): " << (f2->*mptr)(3) << std::endl;
    mptr = &Base::Mul;
    std::cout << "mptr(f1, 3): " << (f1.*mptr)(3) << std::endl;
    std::cout << "mptr(f2, 3): " << (f2->*mptr)(3) << std::endl;

    std::function<int(const Base*, int)> method = &Base::Add;
    std::cout << "method(f1, 3): " << method(&f1, 3) << std::endl;
    std::cout << "method(f2, 3): " << method(f2, 3) << std::endl;
    method = &Base::Mul;
    std::cout << "method(f1, 3): " << method(&f1, 3) << std::endl;
    std::cout << "method(f2, 3): " << method(f2, 3) << std::endl;

    delete f2;

    Base base(2);
    Child child(4);
    NoArgPtr vptr = &Base::Action;
    std::cout << "vptr(base): " << (base.*vptr)() << std::endl;
    std::cout << "vptr(child): " << (child.*vptr)() << std::endl;
    vptr = &Base::VAction;
    std::cout << "vptr(base): " << (base.*vptr)() << std::endl;
    std::cout << "vptr(child): " << (child.*vptr)() << std::endl;

    std::function<std::string(Base&)> vmethod = &Base::Action;
    std::cout << "vmethod(base): " << vmethod(base) << std::endl;
    std::cout << "vmethod(child): " << vmethod(child) << std::endl;
    vmethod = &Base::VAction;
    std::cout << "vmethod(base): " << vmethod(base) << std::endl;
    std::cout << "vmethod(child): " << vmethod(child) << std::endl;

    return 0;
}