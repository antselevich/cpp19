#include <iostream>

// const int edgeLength = 2; 

int main() {
    const int edgeLength = 2; 
    std::cout << "area = " << edgeLength * edgeLength << std::endl;
    int& e = const_cast<int&>(edgeLength);
    // int& e = (int&)(edgeLength);
    e = 0;
    std::cout << "volume = " << edgeLength * edgeLength * edgeLength << std::endl;
    return 0;
}