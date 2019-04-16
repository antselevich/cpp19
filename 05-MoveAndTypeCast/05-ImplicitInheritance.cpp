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
    Yellow y;
    Red& r = y;
    Green& g = y;

    // Yellow& yr = r;
    // Yellow& yg = g;

    std::cout << "&y: " << &y << std::endl;
    std::cout << "&r: " << &r << std::endl;
    std::cout << "&g: " << &g << std::endl;
    return 0;
}