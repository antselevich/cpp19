#include <iostream>

struct Tracker {
    Tracker() : isAlive(true)
    {}
    ~Tracker() {
        isAlive = false;
    }
    bool isAlive;
};

Tracker createTracker() {
    return Tracker();
}
const Tracker& passTracker(const Tracker& tracker) {
    return tracker;
}

int main() {
    const Tracker& tracker = passTracker(createTracker());
    std::cout << "tracker.isAlive " << tracker.isAlive << std::endl;
    return 0;
}
