#include <iostream>
#include <type_traits>

template<typename T>
concept SmallType = sizeof(T) <= 4;

template<typename T>
concept Integral = std::is_integral<T>::value;

template<typename T>
    requires (!SmallType<T> && Integral<T>)
void f(T) {
    std::cout << "With concept" << std::endl;
}

void f(int) {
    std::cout << "With int" << std::endl;
}

// template<typename T>
// struct S {
//     constexpr operator bool() const { return true; }
// };
//
// template<typename T>
//     requires (S<T>{})
// void g(T) {
// }
//
// void g(int) {
// }

int main() {
    f(int());
    f(int64_t());

    // g(0);
    return 0;
}

