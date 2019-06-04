#include <iostream>
#include <functional>
#include <type_traits>

template <typename C>
using HashOperator = size_t(std::hash<C>::*)(const C&) const;

template<typename T>
class IsHashable {
    using YES = int8_t;
    using NO = int16_t;

    template<typename C, HashOperator<C> = &std::hash<C>::operator()>
    struct Wrapper{};

    template <typename C>
    static YES check(Wrapper<C>* p);

    template <typename C>
    static NO check(...);

public:
    static bool const value = std::is_same<YES, decltype(check<T>(0))>::value;
};

template <typename T, typename K = typename std::enable_if<IsHashable<T>::value>::type>
void func(T a) {
    std::cout << "Hashable" << std::endl;
};

int main() {
    func(std::string("abc"));
    // func("A");
    return 0;
}



