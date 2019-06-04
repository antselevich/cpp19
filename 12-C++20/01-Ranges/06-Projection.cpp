#include <iostream>
#include <range/v3/all.hpp> // get everything
#include <vector>

using std::cout;

struct Struct {
    int a;
    int b;
};

int main() {
    std::vector<Struct> vec{Struct{1, 2}, Struct{3, 4}};

    ranges::sort(vec, ranges::greater{}, &Struct::b);

    ranges::for_each(vec, [](const auto &str) { cout << str.b << " "; });
}
