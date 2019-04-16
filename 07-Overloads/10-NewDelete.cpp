#include <iostream>

void* MyMalloc(size_t size) {
    std::cout << "MyMalloc(" << size << ")" << std::endl;
    return malloc(size);
}
void MyFree(void* ptr) {
    std::cout << "MyFree()" << std::endl;
    free(ptr);
}

class MemObj {
public:
    int Val;

    MemObj(int val = 0) : Val(val) {
        std::cout << "MemObj::MemObj" << std::endl;
    }
    ~MemObj() {
        std::cout << "MemObj::~MemObj" << std::endl;
    }

    static void* operator new(size_t size) {
        return MyMalloc(size);
    }
    static void* operator new [] (size_t size) {
        return MyMalloc(size);
    }
    static void operator delete (void* ptr) {
        MyFree(ptr);
    }
    static void operator delete [] (void* ptr) {
        MyFree(ptr);
    }
};

int main() {
    MemObj* one = new MemObj(1);
    std::cout << "val : " << one->Val << std::endl;
    delete one;

    MemObj* two = new MemObj[2];
    for (int i = 0; i < 2; i++) {
        std::cout << "val(" << i << ") : " << two[0].Val << std::endl;
    }
    delete [] two;

    return 0;
}
