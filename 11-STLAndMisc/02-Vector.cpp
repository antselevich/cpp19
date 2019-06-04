#include <iostream>
#include <vector>

struct A {
    // A() = default;

    A(int i, const std::string& o) {
        std::cout << "A constructor called: " << i << ", " << o << std::endl;
    }

    A(const A&) = delete;

    A(A&&) {
        std::cout << "A move constructor called" << std::endl;
    }
};

int main() {
    std::vector<int> v{1, 2, 3};
    v.reserve(2);
    std::cout << v.capacity() << ", " << v.size() << std::endl;
    v.reserve(6);
    std::cout << v.capacity() << ", " << v.size() << std::endl;

    v.reserve(3 + (1 << 24));
    for (size_t i = 0; i < (1 << 24); ++i) {
        if (!(i % (1 << 20))) {
            std::cout << "size: " << v.size() << ", "
                      << "capacity: " << v.capacity() << std::endl;
        }
        v.push_back(i);
    }

    v.resize(5);
    std::cout << v.size() << ", " << v.capacity() << std::endl;
    v.shrink_to_fit();
    std::cout << v.size() << ", " << v.capacity() << std::endl;

    // std::vector<A> vA(3); // needs A::A()
    std::vector<A> vA;
    vA.reserve(2);

    // vA.push_back(A(1, "ololo"));
    vA.emplace_back(1, "ololo");
}
