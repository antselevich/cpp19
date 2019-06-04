#include <iostream>
#include <string>

template <class Func, class T>
void ForEach(Func&& func, T&& t) {
    func(t);
}

template <class Func, class T, class... Args>
void ForEach(Func&& func, T&& t, Args&&... args) {
    func(t);
    ForEach(func, std::forward<Args>(args)...);
}

int main() {
    ForEach(
        [] (auto&& x) { std::cout << x << std::endl; },
        10,
        1.5f,
        "hello"
    );
    return 0;
}