#include <iostream>
#include <range/v3/all.hpp> // get everything
#include <string>
#include <vector>

std::vector<int> get_ints() {
    return {1, 2, 3, 4};
}

int main() {
    auto it1 = std::begin(get_ints());
    std::cout << *it1 << std::endl;

    // auto it2 = ranges::begin(get_ints());
    // std::cout << *it2 << std::endl;
}
