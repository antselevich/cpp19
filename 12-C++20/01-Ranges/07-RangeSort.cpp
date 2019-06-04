#include <iostream>
#include <vector>
#include <algorithm>
#include <range/v3/all.hpp>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
    std::vector<int> values = {1, 2, 3};

    std::sort(
            values.begin(),
            values.end(),
            [](int a, int b) { return a > b; }
    );
    std::for_each(
            values.begin(),
            values.end(),
            [](int value) { cout << value << ' '; }
    );
    cout << std::endl;

    ranges::sort(values, ranges::greater());
    ranges::for_each(values, [](int value) { cout << value << ' '; });
    cout << std::endl;
}
