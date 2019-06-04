#include <iostream>
#include <map>

template<class IT>
auto getX(IT it) {
    return it->first;
}

template<class IT>
auto getY(IT it) {
    return it->second;
}

float f(const std::map<float, float>& points, float x) {
    auto lower = points.lower_bound(x);
    if (lower != points.end()) {
        if (getX(lower) == x || lower == points.begin()) {
            return getY(lower);
        }
        auto cur = lower;
        auto prev = --lower;

        return getY(prev) + (x - getX(prev)) * (getY(cur) - getY(prev)) /
                                     (getX(cur) - getX(prev));
    }
    return 0.0f;
}

int main() {
    std::map<float, float> points = {
        {1.0f, 1.0f},
        {10.0f, 3.0f},
        {10.5f, 4.0f}
    };

    std::cout << "f(5.5f) = " << f(points, 5.5f) << std::endl;
    std::cout << "f(10.0f) = " << f(points, 10.0f) << std::endl;
    std::cout << "f(10.25f) = " << f(points, 10.25f) << std::endl;
    return 0;
}
