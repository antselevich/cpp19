#include <iostream>

constexpr int sume(int a, int b) {
    return a + b;
}

int sum(int a, int b) {
    return a + b;
}

struct ArrSize {
    constexpr ArrSize(bool big) : size(big ? 100 : 5) {}
    size_t size;
};

constexpr size_t fact(size_t n) {
    return n == 1 ? 1 : n * fact(n - 1);
}

int main(int argc, char**) {
    constexpr int a = 3;
    constexpr int b = 5;

    // const int a = argc;
    // const int b = argc + 1;

    constexpr int c = sume(a, b);

    std::cout << c << std::endl;

    int arr[ArrSize(/* big = */ false).size];
    size_t i = 0;
    for (int& elem : arr) {
        elem = i++;
    }

    for (int elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    int arr3[fact(6)];
    std::cout << sizeof(arr3) << std::endl;

    return 0;
}
