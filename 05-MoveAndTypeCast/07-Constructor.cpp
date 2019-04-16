#include <iostream>

struct Foo {
    Foo(const char* _a) : a(_a) {}

    const char* a;
};
struct Bar {
    // explicit Bar(int _a) : a(_a) {}
    Bar(int _a) : a(_a) {}
    Bar(const Foo& foo) {}

    int a;
};

void acceptByVal(Bar bar) {
    std::cout << "acceptByVal, bar.a = " << bar.a << std::endl;
}
void acceptByRef(const Bar& bar) {
    std::cout << "acceptByRef, bar.a = " << bar.a << std::endl;
}
Bar ret(int a) {
    return a;
}

int main() {
    acceptByVal(10.5f);
    acceptByRef(20.5f);
    // acceptByVal("a");
    Bar bar = ret(30);
    std::cout << "bar.a = " << bar.a << std::endl;
    return 0;
}