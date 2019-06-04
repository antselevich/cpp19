#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> src = {1, 4, 5, 7, 2, 3, 9};

    std::vector<int> dest;
    std::copy_if(
        src.begin(),
        src.end(),
        std::back_inserter( dest ),
        [] (int x) -> bool { return x % 2; }
    );

    std::sort(dest.begin(), dest.end());

    for (const auto i : dest) {
        std::cout << i << ", ";
    }
    std::cout << std::endl;
    return 0;
}
