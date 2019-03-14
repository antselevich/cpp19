#include <iostream>

void print(const char* ca, int a,
           const char* cb, int b) {
    std::cout << ca << " = " << a << std::endl <<
                 cb << " = " << b << std::endl << std::endl;
}

int main() {
    int b = 12345;
    int& a = b;
    print("a", a, "b", b);

    b = 54321;
    print("a", a, "b", b);

    int c = 67890;
    a = c;
    print("a", a, "c", c);

    c = 9876;
    print("a", a, "c", c);
    print("a", a, "b", b);

    return 0;
}
