#include <iostream>

class A {
public:
    A() : x(xDefault++) {
        std::cout << "A constructed default: " << x << std::endl;
    }

    A(int _x) : x(_x) {
        std::cout << "A constructed: " << x << std::endl;
    }

    ~A() {
        std::cout << "A destroyed: " << x << std::endl;
    }

    static int xDefault;

private:
    int x;
};

int A::xDefault = 0;


int main() {
    A* a = new A(4);
    delete a;

    A* as = new A[6];
    // delete as;
    delete[] as;

    return 0;
}
