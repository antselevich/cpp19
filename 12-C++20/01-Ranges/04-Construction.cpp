#include <iostream>
#include <range/v3/all.hpp>
#include <string>
#include <vector>

template<ranges::Semiregular T>
class MyContainer {
public:
    std::vector<T> elems;

    template<ranges::InputIterator I>
    MyContainer(I start, ranges::Sentinel<I> end) : elems(start, end) {}

    template<ranges::InputRange R>
    explicit MyContainer(R&& r) : MyContainer(ranges::begin(r), ranges::end(r)) {}
};

int main() {
    std::vector<int> v{1, 2, 3, 4};

    MyContainer<int> c1(v.begin(), v.end());
    for(auto e : c1.elems) {
        std::cout << e << ' ';
    }
    std::cout << std::endl;



    MyContainer<int> c2(v);
    for(auto e : c2.elems) {
        std::cout << e << ' ';
    }
    std::cout << std::endl;
}
