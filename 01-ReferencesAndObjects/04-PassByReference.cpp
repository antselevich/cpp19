#include <iostream>
#include <string>

unsigned int byVal(std::string s) {
    unsigned int sum = 0ULL;
    for (size_t i = 0; i < s.size(); ++i) {
        sum += (unsigned int)s[i];
    }

    return sum;
}

unsigned int byRef(const std::string& s) {
    unsigned int sum = 0ULL;
    for (size_t i = 0; i < s.size(); ++i) {
        sum += (unsigned int)s[i];
    }

    return sum;
}

int main() {
    std::string strs[] = {
        "Lorem ipsum dolor sit amet, consectetur",
        "rLorem ipsum dolor sit amet, consectetu",
        "urLorem ipsum dolor sit amet, consectet",
        "turLorem ipsum dolor sit amet, consecte",
        "eturLorem ipsum dolor sit amet, consect",
        "teturLorem ipsum dolor sit amet, consec",
    };

    unsigned int total = 0ULL;
    for (size_t i = 0; i < 100000000; ++i) {
        total += byVal(strs[i % 6ULL]);
    }

    std::cout << total << std::endl;
    return 0;
}
