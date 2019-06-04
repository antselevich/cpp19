#include <iostream>
#include <typeinfo>

template <class T>
T min(T a, T b) {
    return a < b ? a : b;
}

int oldMin(int a, int b) {
    std::cout << "int min called" << std::endl;
    return a < b ? a : b;
}

// template <class T>
// T oldMin(T a, T b) {
//     std::cout << "tmpl min called" << std::endl;
//     return a < b ? a : b;
// }

template <class T1, class T2>
T1 adaptiveMin(T1 a, T2 b) {
    return static_cast<T1>(a < b ? a : b);
}

template <class T1, class T2>
auto veryAdaptiveMin(T1 a, T2 b) {
    return a < b ? a : b;
}

int main() {
    std::cout << min<int>(1, 2) << std::endl;
    std::cout << min<unsigned long>(4ULL, 2ULL) << std::endl;
    std::cout << min<float>(1.1f, 1.2f) << std::endl;

    std::cout << min(1, 2) << std::endl;
    std::cout << min(4ULL, 2ULL) << std::endl;
    std::cout << min(1.1f, 1.2f) << std::endl;

    std::cout << min(1.1f, std::string{}) << std::endl;

    std::cout << min(1.2f, 1) << std::endl;

    std::cout << oldMin(1, 2) << std::endl;
    std::cout << oldMin(1.1f, 1.2f) << std::endl;

    std::cout << adaptiveMin(1, 2) << std::endl;
    std::cout << adaptiveMin(1.1f, 2) << std::endl;
    std::cout << adaptiveMin(2, 1.1f) << std::endl;

    std::cout << veryAdaptiveMin(1, 2) << " "
              << typeid(veryAdaptiveMin(1, 2)).name() << std::endl;
    std::cout << veryAdaptiveMin(1.1f, 2) << " "
              << typeid(veryAdaptiveMin(1.1f, 2)).name() << std::endl;
    std::cout << veryAdaptiveMin(2, 1.1f) << " "
              << typeid(veryAdaptiveMin(2, 1.1f)).name() << std::endl;
    std::cout << veryAdaptiveMin(1, 2.1f) << " "
              << typeid(veryAdaptiveMin(1, 2.1f)).name() << std::endl;
    return 0;
}
