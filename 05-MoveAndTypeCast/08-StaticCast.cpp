#include <iostream>

struct Int {
    Int(int _x) : x(_x) {
        std::cout << "Int constructed" << std::endl;
    }
    int x;
};

struct Red {
    int r;
};
struct Green {
    int g;
};
struct Yellow : public Red, public Green {
};

int main() {
    int x = static_cast<int>(1.5);
    std::cout << "x = " << x << std::endl;

    Int i = static_cast<Int>(2);

    Yellow y;
    Red& r = y;
    Green& g = y;

    Yellow& yr = static_cast<Yellow&>(r);
    Yellow& yg = static_cast<Yellow&>(g);

    std::cout << "&y: " << &y << std::endl;
    std::cout << "&r: " << &r << std::endl;
    std::cout << "&g: " << &g << std::endl;
    std::cout << "&yg: " << &yg << std::endl;
    std::cout << "&yr: " << &yr << std::endl;


    return 0;
}