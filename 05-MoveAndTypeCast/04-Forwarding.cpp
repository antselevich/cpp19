#include <iostream>

struct Foo {
    int a;
};

void accept(Foo&& foo) {
    foo.a = 10;
    std::cout << "accept by >R< value ref" << std::endl;
}
void accept(const Foo& foo) {
    std::cout << "accept by >L< value ref" << std::endl;
}
void badPass(Foo&& foo) {
    accept(foo);
}
void properPass(Foo&& foo) {
    accept(std::move(foo));
}

int main() {
    badPass(Foo{2});
    properPass(Foo{2});

    {
        Foo&& temp = Foo{2};
        accept(temp);
    }
    {
        Foo&& temp = Foo{2};
        accept(std::forward<Foo>(temp));
    }
    Foo obj{2};
    accept(std::move(obj));
    std::cout << "obj.a: " << obj.a << std::endl;

    return 0;
}