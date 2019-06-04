#include <iostream>
#include <initializer_list>
#include <unordered_map>

class Counter {
public:
    Counter(std::initializer_list<int> in) {
        for (auto elem : in) ++counts[elem];
    }

    size_t getCount(int key) const {
        auto it = counts.find(key);
        if (it == counts.end()) return 0;
        return it->second;
    }

private:
    std::unordered_map<int, size_t> counts;
};

int main() {
    Counter c = {1, 1, 1, 2, 3, 3};
    std::cout << c.getCount(2) << std::endl;
    return 0;
}
