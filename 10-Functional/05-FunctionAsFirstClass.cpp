#include <iostream>
#include <functional>
#include <type_traits>
#include <vector>

template <class T, class R>
std::vector<R> BadMap(const std::vector<T>& items, std::function<R(T)>&& func) {
    std::vector<R> result;
    result.reserve(items.size());
    for (const T& t : items) {
        result.emplace_back(func(t));
    }
    return result;
}

template <class T, class Func>
std::vector<typename std::result_of<Func(T)>::type> ProperMap(const std::vector<T>& items, Func&& func) {
// auto ProperMap(const std::vector<T>& items, Func&& func) {
    std::vector<typename std::result_of<Func(T)>::type> result;
    result.reserve(items.size());
    for (const T& t : items) {
        result.emplace_back(func(t));
    }
    return result;
}

float MulFunc(float x, int a) {
    return x * a;
}

int main() {
    using namespace std::placeholders;

    struct Mul {
        float operator()(int a) {
            return x * a;
        }
        float x;
    };

    std::vector<int> items = {1, 2, 3};
    // std::vector<float> functorRes = BadMap(items, std::function<float(int)>(Mul{0.5f}));
    std::vector<float> functorRes = ProperMap(items, Mul{0.5f});
    std::cout << "functorRes: ";
    for (float a : functorRes) {
        std::cout << a << " ";
    }
    std::cout << std::endl;

    // std::vector<float> bindRes = BadMap(items, std::function<float(int)>(std::bind(MulFunc, 0.5f, _1)));
    std::vector<float> bindRes = ProperMap(items, std::bind(MulFunc, 0.5f, _1));
    std::cout << "bindRes: ";
    for (float a : bindRes) {
        std::cout << a << " ";
    }
    std::cout << std::endl;

    return 0;
}