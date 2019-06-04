#include <iostream>
#include <set>
#include <vector>

template <class T>
void printVector(std::vector<T>&& v) {
    bool first = true;
    for (const auto& elem : v) {
        if (first) {
            first = false;
        } else {
            std::cout << ' ';
        }
        std::cout << elem;
    }
    std::cout << std::endl;
}

int main() {
    printVector(std::vector{8, 15});
    printVector(std::vector(8, 15));

    printVector(std::vector{8});
    // printVector(std::vector(8));

    printVector(std::vector{"ololo", "azaza"});
    // printVector(std::vector("ololo", "azaza"));
}
