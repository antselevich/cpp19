#include <iostream>

class Foo {
public:
    Foo() {
        std::cout << "Foo constructor" << std::endl;
    }

    ~Foo() {
        std::cout << "Foo destructor" << std::endl;
    }
};

class Bar {
public:
    Bar() {
        std::cout << "Bar constructor" << std::endl;
    }

    ~Bar() {
        std::cout << "Bar destructor" << std::endl;
    }
};

class Holder {
public:
    Holder() {
        std::cout << "Holder constructor" << std::endl;
    }

    ~Holder() {
        std::cout << "Holder destructor" << std::endl;
    }

    void Act() const {
        std::cout << "action" << std::endl;
    }

private:
    Foo foo;
    Bar bar;
};

int main() {
    Holder h;
    h.Act();

    return 0;
}
