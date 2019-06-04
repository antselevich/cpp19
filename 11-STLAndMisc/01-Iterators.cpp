#include <iostream>

class MyIterator {
public:
    MyIterator(size_t end)
        : value(0)
        , end(end)
    { }

    int operator*() {
        return value;
    }

    MyIterator operator++() {
        ++value;
        return *this;
    }

    bool operator!=(const MyIterator& other) {
        if (IsEnd() != other.IsEnd()) {
            return true;
        }

        if (IsEnd()) {
            return false;
        }

        return value != other.value;
    }

private:
    bool IsEnd() const {
        return value >= end;
    }

    size_t value;
    size_t end;
};

class RangeOfSize {
public:
    RangeOfSize(size_t size) : size(size) { }

    MyIterator begin() const {
        return MyIterator(size);
    }

    MyIterator end() const {
        return MyIterator(0);
    }

private:
    const size_t size;
};

int main() {

    for (auto i : RangeOfSize(13)) {
        std::cout << i << ", ";
    }

    // {
    //     auto&& __range = RangeOfSize(13);
    //     for (auto __begin = std::begin(__range),
    //               __end = std::end(__range);
    //               __begin != __end; ++__begin) {
    //         auto i = *__begin;
    //         std::cout << i << ", ";
    //     }
    // }

    std::cout << std::endl;
}
