#include <iostream>


template <class... Args>
struct Count;

template <>
struct Count<> {
    static constexpr int result = 0;
};

template <class Head, class... Tail>
struct Count<Head, Tail...> {
    static constexpr int result = 1 + Count<Tail...>::result;
};

int main() {
    std::cout << "Count<>::result : " << Count<>::result << std::endl;
    std::cout << "Count<int>::result : " << Count<int>::result << std::endl;
    std::cout << "Count<int, float>::result : " << Count<int, float>::result << std::endl;
    std::cout << "Count<int, float, char>::result : " << Count<int, float, char>::result << std::endl;

    return 0;
}
