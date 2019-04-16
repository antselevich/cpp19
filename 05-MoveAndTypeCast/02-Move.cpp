#include <iostream>

class IntArray {
public:
    IntArray() : data(nullptr), size(0)
    {}
    IntArray(size_t _size) : 
        data(new int[size]), 
        size(_size) 
    {}
    IntArray(const IntArray& other) :
        data(new int[other.size]), 
        size(other.size) 
    {
        memcpy(data, other.data, size * sizeof(int));
        std::cout << "array was copied" << std::endl;
    }
    ~IntArray() {
        Destroy();
    }

    void Set(size_t index, int val) {
        data[index] = val;
    }
    int Get(size_t index) const {
        return data[index];
    }
    size_t Size() const {
        return size;
    }

    void Assign(const IntArray& other) {
        Destroy();
        data = new int[other.size];
        size = other.size;
        memcpy(data, other.data, size * sizeof(int));
        std::cout << "array was copied" << std::endl;
    }
    void Assign(IntArray&& other) {
        std::swap(data, other.data);
        std::swap(size, other.size);
    }
private:
    void Destroy() {
        if (data != nullptr) {
            delete[] data;
        }
        size = 0;
    }

    int* data;
    size_t size;
};

IntArray createSquares(size_t size) {
    IntArray result(size);
    for (size_t i = 0; i < size; i++) {
        result.Set(i, int(i * i));
    }
    return result;
}

void PrintArray(const IntArray& array) {
    for (size_t i = 0; i < array.Size(); i++) {
        std::cout << array.Get(i) << " "; 
    }
    std::cout << std::endl;
}

int main() {
    IntArray arr = createSquares(3);
    PrintArray(arr);
    
    arr.Assign(createSquares(5));
    PrintArray(arr);

    return 0;
}