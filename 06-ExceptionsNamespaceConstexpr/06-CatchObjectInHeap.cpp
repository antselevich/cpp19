#include <iostream>

struct A {
    char memory[2019];
};

int main() {
    bool flag = false;
    std::cin >> flag;

    try {
        if (flag) {
            A a;
            throw &a;
        } else {
            throw new A();
        }
    } catch (A* a) {
        std::cout << "caught a" << std::endl;
        // delete a;
    }

    return 0;
}
