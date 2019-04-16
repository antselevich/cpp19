#include <iostream>

template <class T>
struct Traits {
    static const bool isRef = false;
    static const bool isConst = false;
};

template <class T>
struct Traits<const T> {
    static const bool isRef = false;
    static const bool isConst = true;
};

template <class T>
struct Traits<T&> {
    static const bool isRef = true;
    static const bool isConst = false;
};

template <class T>
struct Traits<const T&> {
    static const bool isRef = true;
    static const bool isConst = true;
};

int main() {
    int a;
    int& b = a;
    const int& c = a;
    const int d = 0;

    std::cout << "a. isRef " << Traits<decltype(a)>::isRef
              << ", isConst " << Traits<decltype(a)>::isConst << std::endl;
    std::cout << "b. isRef " << Traits<decltype(b)>::isRef
              << ", isConst " << Traits<decltype(b)>::isConst << std::endl;
    std::cout << "c. isRef " << Traits<decltype(c)>::isRef
              << ", isConst " << Traits<decltype(c)>::isConst << std::endl;
    std::cout << "d. isRef " << Traits<decltype(d)>::isRef
              << ", isConst " << Traits<decltype(d)>::isConst << std::endl;

    return 0;
}