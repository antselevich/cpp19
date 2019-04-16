#include <iostream>

namespace A {
int x = 1;
namespace B {
int x = 2;
void f() {
    std::cout << "f " << x << std::endl;
}

void h() {
    std::cout << "h " << x << std::endl;
}
} // namespace B
} // namespace A

namespace A {
void g() {
    std::cout << "g " << x << " " << B::x << std::endl;
    B::f();
    A::B::f();
    // f()

    // namespace alias
    namespace C = A::B;
    C::f();

    using B::h;
    h();
    // f();

    using namespace B;
    f();
    h();
}
} // namespace A

int main() {
    A::g();
    return 0;
}
