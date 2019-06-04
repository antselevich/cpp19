#include <cstring>
#include <iostream>
#include <vector>

class A {
public:
    A(int _id, size_t _size) : id(_id), size(_size) {
        mem = malloc(_size);
    }
    ~A() {
        if (mem) {
            free(mem);
        }
    }
    A(const A& other) : id(other.id), size(other.size) {
        mem = malloc(other.size);
        std::memcpy(mem, other.mem, other.size);

        std::cout << "copied id " << id << std::endl;
    }
    A(A&& other) : id(other.id) {
        std::swap(mem, other.mem);
        std::swap(size, other.size);
        std::cout << "moved id " << id << std::endl;
    }
private:
    int id;
    size_t size = 0;
    void* mem = nullptr;
};

template<class V, class T>
void putAll(V& elems, T&& val) {
    elems.push_back(std::forward<T>(val));
}

template <class V, class T, class... Args>
void putAll(V& elems, T&& val, Args&&... args) {
    elems.push_back(std::forward<T>(val));

    putAll(elems, std::forward<Args>(args)...);
}

int main() {
    A a2(2, 100);
    A a4(4, 54);

    {
        std::vector<A> v;
        v.reserve(4);

        putAll(v, A(1, 13), a2, A(3, 99), a4);
    }
    return 0;
}
