#include <iostream>
#include <range/v3/all.hpp> // get everything
#include <string>
#include <vector>

using ull = unsigned long long;

using namespace ranges::view;

int main() {
    const ull MX = 1e9;
    ull result = ranges::accumulate(
                iota(0ull, MX) |
                filter([](ull x) {return x % 4 != 0;}) |
                transform([](ull x) {return x * x;}),
        0ull);
    std::cout << result << std::endl;
}
