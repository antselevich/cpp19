#include <iostream>

struct Foo {
    Foo() : a(0) {
        std::cout << "Foo constructed" << std::endl;
    }
    Foo(int _a) : a(_a) {
        std::cout << "Foo constructed" << std::endl;
    } 
    Foo(const Foo& other) : a(other.a) {
        std::cout << "Foo copied" << std::endl;
    } 

    virtual ~Foo() {
        std::cout << "Foo destroyed" << std::endl;
    }

    virtual void Do() const {
        std::cout << "Foo::Do, a = " << a << std::endl;
    }

    int a;
};
struct Bar : public Foo {
    Bar(int _a, int _b) : Foo(_a), b(_b) {
        std::cout << "Bar constructed" << std::endl;
    }
    ~Bar() {
        std::cout << "Bar destroyed" << std::endl;
    }

    virtual void Do() const {
        std::cout << "Bar::Do, a = " << a << ", b = " << b << std::endl;
    }

    int b;
};

void badPass(Foo foo) {
    foo.Do();
}
void properPass(const Foo& foo) {
    foo.Do();
}

int main() {
    badPass(Bar(2, 3));
    properPass(Bar(2, 3));
    return 0;
}