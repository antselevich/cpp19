#include <iostream>

class A {
public:
    A() {
        std::cout << "A constructed in " << this << std::endl;
    }

    ~A() {
        std::cout << "A destroyed in " << this << std::endl;
    }
};

static constexpr size_t LEN = 3;

int main() {
    void* rawMemory = malloc(sizeof(A) * LEN);
    std::cout << "rawMemory: " << rawMemory << std::endl;

    for (size_t i = 0; i < LEN; ++i) {
        std::cout << i << ": " << (A*)rawMemory + i << std::endl;
        new ((A*)rawMemory + i) A();
    }

    for (size_t i = 0; i < LEN; ++i) {
        A* a = (A*)rawMemory + i;
        // delete a; // BANG!!1
        a->~A();
    }

    free(rawMemory);

    return 0;
}
