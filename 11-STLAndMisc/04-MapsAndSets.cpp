#include <iostream>
#include <map>
#include <set>
#include <unordered_map>

int main() {
    std::multiset<size_t> elems = {
        3, 1, 5, 1, 3, 2, 5, 1, 1
    };

    std::unordered_map<size_t, size_t> counter;
    for (auto elem : elems) {
        std::cout << elem << ", ";
        ++counter[elem];
    }
    std::cout << std::endl;

    for (auto [key, count] : counter) {
        std::cout << key << " -> " << count << std::endl;
    }

    std::map<size_t, int> sparseArr = {
        {0, -5},
        {14, 15},
        {22, 4}
    };

    std::cout << "Sparse array size before iteration: "
              << sparseArr.size() << std::endl;

    if (!sparseArr.empty()) {
        for (size_t i = 0; i <= sparseArr.rbegin()->first; ++i) {
            // wrong way, will insert:
            // std::cout << sparseArr[i] << ", ";

            // proper way:
            if (auto it = sparseArr.find(i); it != sparseArr.end())
                std::cout << it->second << ", ";
            else
                std::cout << "0, ";
        }
    }
    std::cout << std::endl;

    std::cout << "Sparse array size after iteration: "
              << sparseArr.size() << std::endl
              << "Not sparse anymore =)" << std::endl;

    return 0;
}
