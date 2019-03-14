#include <iostream>
#include <assert.h>

class Array {
public:
    Array(size_t length_) : arr(nullptr), length(length_) {
        arr = (int*)calloc(length, sizeof(int));
    }

    virtual ~Array() {
        if (arr) {
            free(arr);
        }
    }

    int Get(size_t i) const {
        assert(arr);
        assert(i < length);
        return arr[i];
    }

    void Set(size_t i, int val) {
        assert(arr);
        assert(i < length);
        arr[i] = val;
    }

private:
    int* arr;
    size_t length;
};

class Stack : private Array {
public:
    Stack(size_t length_) : Array(length_), top(0) {
    }

    int Pop() {
        assert(top);
        return Get(--top);
    }

    void Push(int val) {
        Set(top++, val);
    }

private:
    size_t top;
};

int main() {
    {
        std::cout << "Array" << std::endl;
        Array a(5);
        a.Set(2, 3);
        // a.Set(7, 3);
        std::cout << a.Get(2) << std::endl;
    }

    std::cout << std::endl;

    {
        std::cout << "Stack" << std::endl;
        Stack s(4);
        // std::cout << s.Pop() << std::endl;
        s.Push(1);
        s.Push(2);
        s.Push(3);
        s.Push(4);
        // std::cout << s.Get(2) << std::endl;
        // s.Push(5);
        std::cout << s.Pop() << std::endl;
        std::cout << s.Pop() << std::endl;
        std::cout << s.Pop() << std::endl;
        std::cout << s.Pop() << std::endl;
    }
    return 0;
}
