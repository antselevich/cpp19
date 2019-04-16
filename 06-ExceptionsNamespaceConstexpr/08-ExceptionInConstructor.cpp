#include <iostream>

struct Internal {
    Internal() {
        std::cout << "Internal constructs" << std::endl;
    }

    ~Internal() {
        std::cout << "Internal destructs" << std::endl;
    }
};

struct External {
    External() {
        std::cout << "External constructs" << std::endl;
        throw false;
    }

    ~External() {
        std::cout << "External destructs" << std::endl;
        // throw false;
    }

    Internal in;
};

int main() {
    try {
        std::cout << "Try create External" << std::endl;
        External* e = new External();

        std::cout << "External created successfully, now free it" << std::endl;
        delete e;
    } catch(bool) {
        std::cout << "Caught bool" << std::endl;
    }
    return 0;
}
