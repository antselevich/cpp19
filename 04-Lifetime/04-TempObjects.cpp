#include <iostream>

class Tracker {
public:
    Tracker(const char* _name) :
        name(_name),
        version(0)
    {
        std::cout
            << name << ", " << version
            << " was created" << std::endl;
    }
    Tracker(const Tracker& other) :
        name(other.name),
        version(other.version + 1)
    {
        std::cout
            << name << ", " << version
            << " was copied" << std::endl;
    }
    ~Tracker() {
        std::cout
            << name << ", " << version
            << " was destroyed" << std::endl;
    }
private:
    const char* name;
    int version;
};

Tracker createTracker(const char* name) {
    return Tracker(name);
}
void acceptTrackers(Tracker tracker1, Tracker tracker2) {
    std::cout << "acceptTracker body" << std::endl;
}
void acceptTrackersRef(const Tracker& tracker1, const Tracker& tracker2) {
    std::cout << "acceptTrackerRef body" << std::endl;
}

int main() {
    // acceptTrackers(createTracker("foo"), createTracker("bar"));
    // acceptTrackersRef(createTracker("foo"), createTracker("bar"));
    return 0;
}
