#include <iostream>

struct BadParent {
    BadParent() {
        std::cout << "BadParent constructor" << std::endl;
    }
    ~BadParent() {
        std::cout << "BadParent destructor" << std::endl;
    }
};

struct BadChild : public BadParent {
    BadChild() : mem(nullptr) {
        std::cout << "BadChild constructor" << std::endl;
        mem = malloc(146);
    }
    ~BadChild() {
        std::cout << "BadChild destructor" << std::endl;
        if (mem) {
            free(mem);
        }
    }
private:
    void* mem;
};

struct GoodParent {
    GoodParent() {
        std::cout << "GoodParent constructor" << std::endl;
    }
    virtual ~GoodParent() {
        std::cout << "GoodParent destructor" << std::endl;
    }
};

struct GoodChild : public GoodParent {
    GoodChild() : mem(nullptr) {
        std::cout << "GoodChild constructor" << std::endl;
        mem = malloc(192);
    }
    ~GoodChild() {
        std::cout << "GoodChild destructor" << std::endl;
        if (mem) {
            free(mem);
        }
    }
private:
    void* mem;
};

int main() {
	BadParent* bad = new BadChild;
	delete bad;

	GoodParent* good = new GoodChild;
	delete good;
}
