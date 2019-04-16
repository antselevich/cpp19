#include <iostream>

struct Arithm {
    Arithm(int val = 0) : Val(val) {
    }
    Arithm(const Arithm& op): Val(op.Val) {
    }

    Arithm& operator = (const Arithm& op) {
        Val = op.Val;
        return *this;
    }
    Arithm& operator = (int val) {
        Val = val;
        return *this;
    }

    int Val;
};

Arithm operator + (const Arithm& lv, const Arithm& rv) {
    return Arithm(lv.Val + rv.Val);
}

std::ostream& operator << (std::ostream& stream, const Arithm& a) {
    stream << "Arithm(" << a.Val << ")";
    return stream;
}

void main() {
    Arithm a;
    Arithm b;
    a = b = 3;
    std::cout << "a + b = " << a + b << std::endl;
    Arithm c = a + b;
}