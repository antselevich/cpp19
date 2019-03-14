#include <iostream>

void inc(int& a) {
    a++;
}

void badinc(int a) {
    a++;
}

/*void verybadinc(const int& a) {
    a++;
}*/

int main() {
    int b = 15;

    badinc(b);
    badinc(b);
    badinc(b);
    badinc(b);
    badinc(b);
    std::cout << b << std::endl;

    return 0;
}
