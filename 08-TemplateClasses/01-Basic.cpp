#include <iostream>

struct Foo {
    Foo(int _x) : x(_x) {
        std::cout << "Foo::Foo(" << _x << ")" << std::endl;
    }
    ~Foo() {
        std::cout << "Foo::~Foo()" << std::endl;
    }

    int x;
};

struct Bar {
    Bar(double _x) : x(_x) {
        std::cout << "Bar::Bar(" << _x << ")" << std::endl;
    }
    ~Bar() {
        std::cout << "Bar::~Bar()" << std::endl;
    }

    double x;
};

template <class T>
class Holder {
public:
    Holder(T* _ptr) : ptr(_ptr) {}
    Holder(Holder&& other) : ptr(other.ptr) {
        other.ptr = nullptr;
    }
    Holder(const Holder&) = delete;

    Holder& operator = (Holder&& other) {
        std::swap(ptr, other.ptr);
        return *this;
    }
    Holder& operator = (const Holder& other) = delete;
    
    ~Holder() {
        delete ptr;
    }

    T* operator -> ();

    T& operator * () {
        return *ptr;
    }
private:
    T* ptr;
};

template <class T>
T* Holder<T>::operator -> () {
    return ptr;
}

int main() {
    Holder<Foo> hf(new Foo(5));
    Holder<Bar> hb(new Bar(5.5));

    hf->x = 10;
    std::cout << "hf->x: " << hf->x << std::endl;
    std::cout << "hb->x: " << hb->x << std::endl;
    // Holder<Bar> fb(new Foo(5));

    Holder<const Foo> hcf(new Foo(5));
    // hcf->x = 10;
    std::cout << "hcf->x: " << hcf->x << std::endl;

    return 0;
}