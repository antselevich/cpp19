#include <iostream>
#include <string>

struct CastFoo {
    CastFoo(int x) : X(x) {}
    operator int() const {
        return X;
    }
    explicit operator std::string() const {
        return std::to_string(X);
    }
    int X;
};
struct CastBar {
    CastBar(int x) : X(x) {}
    CastBar(const CastFoo& cf) : X(cf.X) {}
    explicit operator bool() const {
        return X != 0;
    }
    int X;
};

int main() {
    int a = CastFoo(10);
    std::cout << "a = " << a << std::endl;
    // std::string s = CastFoo(2); // error!
    std::string s = static_cast<std::string>(CastFoo(2));
    std::cout << "s = \"" << s << "\"" << std::endl;

    CastBar bar(10);
    if (bar) {
        std::cout << "cast to bool" << std::endl;
    }

    int x = bar;
    std::cout << "x = " << x << std::endl;

    return 0;
}
