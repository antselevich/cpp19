#include <iostream>
#include <string>
#include <vector>

using ull = unsigned long long;

int main() {
    ull result = 0;
    const ull MX = 1e9;
    for(ull i = 0; i < MX; ++i) {
        if (i % 4 != 0) {
            result += i * i;
        }
    }
    std::cout << result << std::endl;
}
