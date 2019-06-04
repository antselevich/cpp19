#include <iostream>
#include <memory>

struct A {
public:
    A(int x) : x(x) {
        std::cout << "A constructed" << std::endl;
    }

    A() : A(0) {
    }

    ~A() {
        std::cout << "A destructed" << std::endl;
    }

    void Act() const {
        std::cout << "Act " << x << std::endl;
    }

private:
    int x;
};

class AHolder {
public:
    AHolder(A* raw) : ptr(raw) { }

private:
    std::unique_ptr<A> ptr;
};

void getOwnership(A* raw) {
    std::unique_ptr<A> ptr(raw);
}

int main() {
    {
        std::auto_ptr<A> ptr(new A(3));
        std::auto_ptr<A> ptr2 = ptr;

        ptr2->Act();

        // // Bang
        // ptr->Act();
    }

    {
        std::unique_ptr<A> ptr(new A(3));
        // std::unique_ptr<A> ptr2 = ptr;
        std::unique_ptr<A> ptr2 = std::move(ptr);

        ptr2->Act();
    }

    {
        AHolder holder(new A(6));
        // AHolder holder2 = holder; // won't compile
    }

    {
        getOwnership(new A(2));
    }

    {
        A* raw = new A[4];

        // // Bang
        // std::unique_ptr<A> ptr(raw);

        std::unique_ptr<A[]> ptr(raw);
    }

    return 0;
}
