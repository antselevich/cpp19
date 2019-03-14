#include <iostream>

struct Parent {
    Parent() {
        std::cout << "Parent constructor" << std::endl;
        foo();
        // bar(); // BANG 1!!
    }
    virtual ~Parent() {
        std::cout << "Parent destructor" << std::endl;
        foo();
        // bar(); // BANG 1!!
    }
    virtual void foo() const {
        std::cout << "Parent::foo" << std::endl;
    }
    virtual void bar() const = 0;
};

struct Child : public Parent {
    Child() {
        std::cout << "Child constructor" << std::endl;
        foo();
    }
    ~Child() {
        std::cout << "Child destructor" << std::endl;
        foo();
    }
    void foo() const override final {
        std::cout << "Child::foo" << std::endl;
    }
    void bar() const override final {
        std::cout << "Parent::foo" << std::endl;
    }
};

int main() {
    Child child;

    return 0;
}
