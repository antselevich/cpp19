#include <iostream>

struct FirstBase {
    int fa;
    int fb;
};
struct SecondBase {
    int sa;
    int sb;
};
struct Derived: public FirstBase, public SecondBase {
    int da;
    int db;
};

int main() {
    Derived d;
    std::cout << &d.fa << ": first base" << std::endl;
    std::cout << &d.sa << ": second base" << std::endl;
    std::cout << &d.da << ": derived" << std::endl;
    return 0;
}