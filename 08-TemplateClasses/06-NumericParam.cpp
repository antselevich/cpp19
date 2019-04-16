#include <iostream>

template <class T, size_t size>
struct Array {
    T data[size];
};

template <size_t n>
struct Fact {
    static const size_t result = n * Fact<n - 1>::result;
};
template <>
struct Fact< 0 > {
    static const size_t result = 1;
};

int main() {
    Array<int, 8> intArray;
    Array<double, 10> doubleArray;
    std::cout << "sizeof(intArray.data): " << sizeof(intArray.data) << std::endl;
    std::cout << "sizeof(doubleArray.data): " << sizeof(doubleArray.data) << std::endl;

    std::cout << "Fact<6>::result : " << Fact<6>::result << std::endl;

    return 0;
}