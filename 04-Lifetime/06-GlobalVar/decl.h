#pragma once

#include <iostream>

struct Tracker {
    Tracker(const char* _name, int _val) :
        name(_name),
        val(_val)
    {
        std::cout
            << name << ", " << val
            << " was created" << std::endl;
    }
    Tracker(const Tracker& other) :
        name(other.name),
        val(other.val)
    {
        std::cout
            << name << ", " << val
            << " was copied" << std::endl;
    }
    ~Tracker() {
        std::cout
            << name << ", " << val
            << " was destroyed" << std::endl;
    }

    const char* name;
    int val;
};

extern Tracker u11;
extern Tracker u12;
extern Tracker u21;
extern Tracker u22;
