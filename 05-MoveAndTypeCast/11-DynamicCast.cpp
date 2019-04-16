#include <iostream>

struct Red {
    virtual ~Red() {}

    int r;
};
struct Green {
    virtual ~Green() {}

    int g;
};
struct Yellow : public Red, public Green {
};

int main() {
    Red red;
    Green green;
    Yellow yellow;

    Red* redYellow = &yellow;
    Red* redRed = &red;
    Green* greenYellow = &yellow;
    Green* greenGreen = &green;

    std::cout 
        << "dynamic_cast<Yellow*>(redYellow): " 
        << dynamic_cast<Yellow*>(redYellow) << std::endl; 
    std::cout 
        << "dynamic_cast<Yellow*>(redRed): " 
        << dynamic_cast<Yellow*>(redRed) << std::endl; 
    std::cout 
        << "dynamic_cast<Yellow*>(greenYellow): " 
        << dynamic_cast<Yellow*>(greenYellow) << std::endl; 
    std::cout 
        << "dynamic_cast<Yellow*>(greenGreen): " 
        << dynamic_cast<Yellow*>(greenGreen) << std::endl; 
    
    std::cout << std::endl;
    
    std::cout 
        << "dynamic_cast<Red*>(greenYellow): " 
        << dynamic_cast<Red*>(greenYellow) << std::endl; 
    std::cout 
        << "dynamic_cast<Red*>(greenGreen): " 
        << dynamic_cast<Red*>(greenGreen) << std::endl; 
    std::cout 
        << "dynamic_cast<Green*>(greenYellow): " 
        << dynamic_cast<Green*>(greenYellow) << std::endl; 
    std::cout 
        << "dynamic_cast<Green*>(redRed): " 
        << dynamic_cast<Green*>(redRed) << std::endl; 
}
