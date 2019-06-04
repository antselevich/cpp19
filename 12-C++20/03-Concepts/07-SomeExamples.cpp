#include <iostream>
#include <vector>

using namespace std::literals;


template <typename T>
concept SizeField = requires (T a){
    { a.size } -> std::size_t;
};

template <typename T>
concept SizeMethod = requires (T a){
    { a.size() } noexcept -> std::size_t;
    typename T::type;
    ++a;
};


template <SizeField T>
size_t get_size(const T& a) {
    std::cout << "Field" << std::endl;
    return a.size;
}

template <SizeMethod T>
std::size_t get_size(const T& a) {
    std::cout << "Method" << std::endl;
    return a.size();
}

struct A {
    std::size_t size = 10;
};

struct B {
    std::size_t size() const noexcept {
        return 10;
    }
};

int main() {
    std::cout << get_size(A()) << std::endl;
    std::cout << get_size(B()) << std::endl;

    std::cout << get_size(std::vector<int>(30)) << std::endl;;

    return 0;
}