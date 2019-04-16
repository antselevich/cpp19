#include <iostream>

class Tracker {
public:
    Tracker(const char* _name) : name(_name) {
        std::cout << name << " was created" << std::endl;
    }
    Tracker(const Tracker& other) : name(other.name) {
        std::cout << name << " was copied" << std::endl;
    }
    Tracker(Tracker&& other) : name(other.name) {
        std::cout << name << " was moved" << std::endl;
    }
    ~Tracker() {
        std::cout << name << " was destroyed" << std::endl;
    }
private:
    const char* name;
};

Tracker retTracker(const char* name) {
    return Tracker(name); 
}

int main() {
    Tracker tracker = retTracker("foo");
    return 0;
}