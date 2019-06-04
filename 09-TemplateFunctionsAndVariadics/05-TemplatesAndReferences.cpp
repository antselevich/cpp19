#include <iostream>
#include <vector>

class MyClass {
public:
    void Modify() {}
};

template <class T>
void expectLvalue (const T& t) {
    std::cout << "expectLvalue" << std::endl;
    std::cout << "lvalue: " << std::is_lvalue_reference<decltype(t)>() << std::endl;
    std::cout << "rvalue: " << std::is_rvalue_reference<decltype(t)>() << std::endl;
}

template <class T>
void expectRorLvalue (T&& t) {
    std::cout << "expectRorLvalue" << std::endl;
    std::cout << "lvalue: " << std::is_lvalue_reference<decltype(t)>() << std::endl;
    std::cout << "rvalue: " << std::is_rvalue_reference<decltype(t)>() << std::endl;
    // t.Modify();
}

void expectRvalue(MyClass&& m) {
    std::cout << "expectRvalue" << std::endl;
    std::cout << "lvalue: " << std::is_lvalue_reference<decltype(m)>() << std::endl;
    std::cout << "rvalue: " << std::is_rvalue_reference<decltype(m)>() << std::endl;
}

int main() {
    std::cout << "lvalue" << std::endl;
    MyClass m;
    expectLvalue(m);
    expectRorLvalue(m);
    // expectRvalue(m);
    expectRvalue(std::move(m));

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "const lvalue" << std::endl;
    const MyClass cm;
    expectLvalue(cm);
    expectRorLvalue(cm);
    // expectRvalue(cm);
    // expectRvalue(std::move(cm));
    expectRvalue(std::move(const_cast<MyClass&>(cm)));

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "rvalue" << std::endl;
    expectLvalue(MyClass());
    expectRorLvalue(MyClass());
    expectRvalue(MyClass());
    return 0;
}
