#include <iostream>

class Mom {
public:
    Mom(int _x): x(_x) {
        std::cout
            << "Mom constructor, x = "
            << x
            << std::endl;
    }
private:
    int x;
};
class Dad {
public:
    Dad(int _y): y(_y) {
        std::cout
            << "Dad constructor, x = "
            << y
            << std::endl;
    }
private:
    int y;
};
class Son: public Mom, public Dad {
public:
    Son(): Mom(1), Dad(2) {
        std::cout << "Son constructor" << std::endl;
    }
private:
    int z;
};

int main() {
    Son son;
    return 0;
}
