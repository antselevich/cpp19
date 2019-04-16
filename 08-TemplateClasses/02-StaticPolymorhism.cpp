#include <iostream>

template <class T>
class Summator {
public:
    Summator(const T& initialValue) : value(initialValue) {}
    const T& result() const {
        return value;
    }
    Summator& add(const T& newValue) {
        value += newValue;
        return *this;
    }
private:
    T value;
};

#include <string>
#include <complex>
#include <vector>

int main() {
    std::cout << "int sum: " 
        << Summator<int>(0).add(1).add(2).result()
        << std::endl;
    std::cout << "float sum: " 
        << Summator<float>(0.0f).add(1.5f).add(2.5f).result()
        << std::endl;
    std::cout << "complex sum: " 
        << Summator<std::complex<float>>(0.0f).add(1.5f).add(2.5f).result()
        << std::endl;

    std::vector<int> v = Summator<std::vector<int>>(std::vector<int>()).result();
    // std::vector<int> v = 
    //     Summator<std::vector<int>>(std::vector<int>())
    //     .add(std::vector<int>())
    //     .result();

    return 0;
}