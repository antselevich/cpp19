#include <iostream>

class A {
public:
    A(int val) : Val(val) {
        std::cout << "A::A(" << val << ")" << std::endl;
    }

    int Val;
};

class B : public virtual A {
public:
    B(int val) : A(val + 2) {
        std::cout << "B::B(" << val << ")" << std::endl;
    }
};

class C : public virtual A {
public:
    C(int val) : A(val + 1) {
        std::cout << "C::C(" << val << ")" << std::endl;
    }
};

class D : public B, public C {
public:
    D(int val) : A(val + 2), B(val + 20), C(val + 20) {
        std::cout << "D::D(" << val << ")" << std::endl;
    }

    void Print() const {
        std::cout << "val: " << Val << std::endl;
    }
};

int main() {
    C c(1);
    std::cout << "c created" << std::endl;
    B b(2);
    std::cout << "b created" << std::endl;
    D d(3);
    std::cout << "d created" << std::endl;
    d.Print();
    return 0;
}
