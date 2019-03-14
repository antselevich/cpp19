#include <iostream>

struct Base {
    Base(int _x): x(_x) {}

    int x;
};
struct FirstMiddle: public Base {
    FirstMiddle(): Base(1), a(20) {}

    int a;
};
struct SecondMiddle: public Base {
    SecondMiddle(): Base(2), a(30) {}

    int a;
};
struct Derived: public FirstMiddle, public SecondMiddle {
    void Access() {
        std::cout
            // << "just x: "
            // << x << std::endl
            << "first middle base x: "
            << FirstMiddle::Base::x << std::endl
            << "second middle base x: "
            << SecondMiddle::x << std::endl
            // << "just a: "
            // << a << std::endl
            << "first middle a: "
            << FirstMiddle::a << std::endl
            << "second middle a: "
            << SecondMiddle::a << std::endl;
    }
};

int main() {
    Derived d;
    d.Access();
    return 0;
}
