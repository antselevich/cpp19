#include <iostream>

struct HeavyObject {
    HeavyObject(const char* name_) : name(name_), memory(malloc(1000)) {
        std::cout << "Construct heavy object " << name  << std::endl;
    }

    ~HeavyObject() {
        std::cout << "Destroy heavy object " << name << std::endl;
        if (memory) {
            free(memory);
        }
    }

    const char* name;
    void* memory = nullptr;
};


void f() {
    HeavyObject f1("_f1_");
    HeavyObject f2("_f2_");
    HeavyObject f3("_f3_");

    throw "ololo";
    // exit(0);

    HeavyObject f4("_f4_");
    HeavyObject f5("_f5_");
}

void g() /* noexcept */ {
    HeavyObject g1("_g1_");
    HeavyObject g2("_g2_");

    f();

    HeavyObject g3("_g3_");
}

int main() {
    HeavyObject main1("_main1_");

    try {
        g();
    } catch (const char* msg) {
        std::cout << "Caught: " << msg << std::endl;
    }

    HeavyObject main2("_main2_");

    try {
        g();
    } catch (const char* msg) {
        std::cout << "Caught: " << msg << std::endl;
    }

    HeavyObject main3("_main3_");
    // g();
}
