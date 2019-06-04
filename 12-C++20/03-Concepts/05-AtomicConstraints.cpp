#include <iostream>

template<class T> constexpr bool is_meowable = true;
template<class T> constexpr bool is_cat = true;

template<class T>
concept Meowable = is_meowable<T>;

template<class T>
concept BadMeowableCat = is_meowable<T> && is_cat<T>;

template<class T>
concept GoodMeowableCat = Meowable<T> && is_cat<T>;

template<Meowable T>
void f1(T){
    std::cout << "Meowable" << std::endl;
}

template<BadMeowableCat T>
void f1(T){
    std::cout << "BadMeowableCat" << std::endl;
}

template<Meowable T>
void f2(T) {
    std::cout << "Meowable" << std::endl;
}

template<GoodMeowableCat T>
void f2(T) {
    std::cout << "GoodMeowableCat" << std::endl;
}

int main() {
    f1(0); // error, ambiguous:
    // the is_meowable<T> in Meowable and BadMeowableCat forms distinct
    // atomic constraints that are not identical (and so do not subsume each other)

    f2(0); // OK, calls #4, more constrained than #3
    // GoodMeowableCat got its is_meowable<T> from Meowable
}