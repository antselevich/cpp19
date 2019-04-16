#include <iostream>

template <class T>
class DynArray {
public:
    DynArray(size_t size) : ptr(new T[size]) 
    {}
    ~DynArray() {
        delete[] ptr;
    }
    void set(size_t index, const T& value) {
        ptr[index] = value;
    }
    const T& get(size_t index) {
        return ptr[index];
    }
private:
    T* ptr;
};

template <>
class DynArray<bool> {
public:
    static const size_t baseSize = sizeof(uint64_t) * 8;
    DynArray(size_t size) : ptr(new uint64_t[size / baseSize + (size % baseSize != 0)]) 
    {}
    ~DynArray() {
        delete[] ptr;
    }
    void set(size_t index, bool value) {
        if (value) {
            ptr[index / baseSize] |= (uint64_t(1) << (index % baseSize));
        } else {
            ptr[index / baseSize] &= ~(uint64_t(1) << (index % baseSize));
        }
    }
    bool get(size_t index) const {
        return (ptr[index / baseSize] >> (index % baseSize)) & 0x01;
    }
private:
    uint64_t* ptr;
};

int main() {
    const size_t size = 10;
    DynArray<int> ia(size);
    for (size_t i = 0; i < size; i++) {
        ia.set(i, i * i);
    }
    for (size_t i = 0; i < size; i++) {
        std::cout << ia.get(i) << " ";        
    }
    std::cout << std::endl;

    DynArray<bool> ba(10);
    for (size_t i = 0; i < size; i++) {
        ba.set(i, i % 3 == 0);
    }
    for (size_t i = 0; i < size; i++) {
        std::cout << ba.get(i) << " ";        
    }
    std::cout << std::endl;

    return 0;
}