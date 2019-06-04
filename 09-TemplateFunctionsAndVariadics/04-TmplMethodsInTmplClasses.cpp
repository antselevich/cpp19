#include <iostream>
#include <iomanip>

template <bool pretty = false>
struct Printer {
    template <class T>
    void operator()(T value) const;
};

template <> template <class T>
void Printer</* pretty = */ false>::operator()(T value) const {
    std::cout << "non-pretty for any type; " << value << std::endl;
}

// Won't compile
// template <bool pretty> template <>
// void Printer<pretty>::operator()(float value) const {
//     std::cout << "pretty or not for float" << value << std::endl;
// }

template <> template <>
void Printer</* pretty = */ true>::operator()(float value) const {
    std::cout << "pretty for float; " << std::setprecision(3) << value << std::endl;
}

int main() {
    Printer<false> pr;
    pr(1);
    pr("ololo");

    Printer<true> pretty;

    // Won't compile
    // pretty("ololo");

    pretty(3.141592f);
    return 0;
}
