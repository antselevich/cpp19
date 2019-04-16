#include <iostream>

struct Data {
    int Val;
};

class UniquePtr {
public:
    UniquePtr(Data* ptr) : Ptr(ptr) {
    }
    ~UniquePtr() {
        delete Ptr;
    }

    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator = (const UniquePtr&) = delete;

    Data& operator * () {
        return *Ptr;
    }
    Data* operator -> () {
        return Ptr;
    }
private:
    Data* Ptr;
};

int main() {
    UniquePtr uptr(new Data {2});
    uptr->Val = 1;
    std::cout << "(*uptr).val " << (*uptr).Val << std::endl;

    return 0;
}