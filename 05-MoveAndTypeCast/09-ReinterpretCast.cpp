#include <iostream>

struct Red {
    int r;
};
struct Green {
    int g;
};
struct Yellow : public Red, public Green {
};

int main() {
    float a = 1.0f;
    // int* ai = static_cast<int*>(&a);
    // int* ai = (int*)(&a);
    int* ai = reinterpret_cast<int*>(&a);
    std::cout << "a as int = " << *ai << std::endl;

    Yellow y;
    Red& r = y;
    Green& g = y;

    Yellow& yr = reinterpret_cast<Yellow&>(r);
    Yellow& yg = reinterpret_cast<Yellow&>(g);

    std::cout << "&y: " << &y << std::endl;
    std::cout << "&r: " << &r << std::endl;
    std::cout << "&g: " << &g << std::endl;
    std::cout << "&yg: " << &yg << std::endl;
    std::cout << "&yr: " << &yr << std::endl;

    // Yellow& cyg = (Yellow&)g;
    // std::cout << "&cyg: " << &cyg << std::endl;

    return 0;
}