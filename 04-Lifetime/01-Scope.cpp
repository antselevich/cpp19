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

void simple() {
    Tracker tracker("simple obj");
    std::cout << "simple body" << std::endl;
}

void scope() {
    Tracker tracker("outer");
    {
        Tracker tracker("inner");
        std::cout << "inner body" << std::endl;
    }
}

void loop() {
    for (int i = 0; i < 3; i++) {
        Tracker tracker("iteration");
    }
}

int main() {
    simple();
    scope();
    loop();
    return 0;
}