#include <iostream>

class MyClass {
public:
    MyClass(int _x) : x(_x), f_x(x + 1) {
    }

    int GetF() {
        return f_x;
    }

private:
    int f_x;
    int x;
};

int main() {
    MyClass c(4);
    std::cout << c.GetF() << std::endl;
    return 0;
}
