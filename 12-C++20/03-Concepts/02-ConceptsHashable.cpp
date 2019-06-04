#include <string>
#include <cstddef>
#include <iostream>

using namespace std::literals;

template<typename T>
concept Hashable = requires(T a) {
    { std::hash<T>{}(a) } -> std::size_t;
};


template<Hashable T>
void f(T a) {
    std::cout << "Hashable" << std::endl;
}

// template<typename T>
//    requires Hashable<T>
// void f(T);
//
// template<typename T>
// void f(T) requires Hashable<T>;

int main() {
    f("abc"s);
    f(1);
    f(std::pair{1, 2});
}