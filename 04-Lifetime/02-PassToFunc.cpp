#include <iostream>

class Tracker {
public:
    Tracker(const char* _name) : name(_name) {
        std::cout << name << " was created" << std::endl;
    }
    ~Tracker() {
        std::cout << name << " was destroyed" << std::endl;
    }
private:
    const char* name;
};

void acceptTracker(Tracker tracker) {
    std::cout << "acceptTracker body" << std::endl;
}

class AdvTracker {
public:
    AdvTracker(const char* _name) : name(_name) {
        std::cout << name << " was created" << std::endl;
    }
    AdvTracker(const AdvTracker& other) : name(other.name) {
        std::cout << name << " was copied" << std::endl;
    }
    ~AdvTracker() {
        std::cout << name << " was destroyed" << std::endl;
    }
private:
    const char* name;
};

void acceptAdvTracker(AdvTracker tracker) {
    std::cout << "acceptAdvTracker body" << std::endl;
}

int main() {
    Tracker tracker("obj");
    acceptTracker(tracker);
    AdvTracker advTracker("adv obj");
    acceptAdvTracker(advTracker);
    return 0;
}