#include <iostream>

class IntOrString {
public:
    template <class T>
    explicit IntOrString(T value);

    template <class T>
    T TryAs() const;

private:
    enum {
        INT,
        STRING,
        NONE
    } Type = NONE;

    union {
        int i;
        const char* c;
    } U;
};

template <>
IntOrString::IntOrString(int value)
    : Type(INT)
{
    U.i = value;
    std::cout << "int constructor called" << std::endl;
}

template <>
IntOrString::IntOrString(const char* value)
    : Type(STRING)
{
    U.c = value;
    std::cout << "string constructor called" << std::endl;
}

template <>
int IntOrString::TryAs<int>() const {
    if (INT != Type) throw std::exception();
    return U.i;
}

template <>
const char* IntOrString::TryAs<const char*>() const {
    if (STRING != Type) throw std::exception();
    return U.c;
}

int main() {
    IntOrString ios("ololo");
    std::cout << ios.TryAs<const char*>() << std::endl;
    return 0;
}
