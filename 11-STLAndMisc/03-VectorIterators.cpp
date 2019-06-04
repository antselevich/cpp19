#include <iostream>
#include <vector>

int main() {
    std::vector<size_t> elems(5, 2);

    // std::vector<size_t>::const_iterator it = elems.cbegin();
    auto it = elems.cbegin();

    // Invalidates iterator it
    // elems.push_back(6);

    while (it != elems.end()) {
        std::cout << *it++ << ", ";
    }
    std::cout << std::endl;

    std::vector<size_t> elems2{1, 2, 3, 4, 5, 6};

    // for (auto it2 = elems2.begin(); it2 != elems2.end(); ++it2) {
    //     if ((*it2) % 2 == 0) {
    //         elems2.erase(it2);
    //     }
    // }

    // proper erase
    for (auto it2 = elems2.begin(); it2 != elems2.end();) {
        if ((*it2) % 2 == 0) {
            it2 = elems2.erase(it2);
        } else {
            ++it2;
        }
    }

    for (auto elem : elems2) {
        std::cout << elem << ", ";
    }
    std::cout << std::endl;

    return 0;
}
