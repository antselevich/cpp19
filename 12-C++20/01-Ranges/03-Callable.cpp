#include <iostream>
#include <range/v3/all.hpp> // get everything
#include <string>
#include <vector>
#include <algorithm>

struct Speaker {
    void Say() {
        std::cout << "Hello!!!" << std::endl;
    }
};

int main() {
    std::vector<Speaker> speakers(10);

    // std::for_each(speakers.begin(), speakers.end(), &Speaker::Say);
    ranges::for_each(speakers, &Speaker::Say);
}
