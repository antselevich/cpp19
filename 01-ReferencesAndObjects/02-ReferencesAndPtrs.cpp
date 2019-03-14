#include <iostream>

int main() {
    float f1 = 0.1f;
    float& f2 = f1; // float& f2;
    float* f3;

    std::cout << &f1 << " -> " << f1 << std::endl;
    std::cout << &f2 << " -> " << f2 << std::endl;

    f3 = &f1;
    std::cout << f3 << " -> " << *f3 << std::endl;

    f3 = &f2;
    std::cout << f3 << " -> " << *f3 << std::endl;

    float& f4 = f2;
    std::cout << &f4 << " -> " << f4 << std::endl;

    f3 = (float*)0XDEADBEEF;
    std::cout << f3 << /*" -> " << *f3 <<*/ std::endl;

    float*& f5 = f3;
    f5 = (float*)0XBEEFDEAD;
    std::cout << f3 << ", " << f5 << std::endl;

    // float&* f6 = &f4;

    return 0;
}
