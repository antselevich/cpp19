#include <iostream>
#include <vector>

template <class T, class Func>
std::vector<typename std::result_of<Func(T)>::type> ProperMap(const std::vector<T>& items, Func&& func) {
    std::vector<typename std::result_of<Func(T)>::type> result;
    result.reserve(items.size());
    for (const T& t : items) {
        result.emplace_back(func(t));
    }
    return result;
}

int main() {
    std::vector<int> items = {1, 2, 3};
    std::vector<float> functorRes = ProperMap(items, [] (int a) { return 0.5f * a; });
    std::cout << "functorRes: ";
    for (float a : functorRes) {
        std::cout << a << " ";
    }
    std::cout << std::endl;
    return 0;
}