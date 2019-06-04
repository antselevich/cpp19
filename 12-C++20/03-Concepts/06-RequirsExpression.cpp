#include <iostream>

using namespace std::literals;

// template<typename T>
// requires requires (T x) { x + x; }
// T add(T a, T b) { return a + b; }

template<typename T>
concept Addable = requires (T x) {
    x + x;
};

template<typename T> requires Addable<T>
T add(T a, T b) { return a + b; }

template <typename A, typename B>
concept Summable = requires (A a, B b) {
    a + b;
};

template <typename A, typename B>
auto add(A a, B b) requires Summable<A, B> {
    return a + b;
};

int main() {
    std::cout << "add(1, 2) = " << add(1, 2) << std::endl;
    std::cout << "add(\"abc\", \"def\") = " << add("abc"s, "def"s) << std::endl;
    std::cout << "add(\"abc\", 'd') = " << add("abc"s, 'd') << std::endl;
    add("ab"s, 1);
    return 0;
}