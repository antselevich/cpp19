#include <iostream>

struct Base {
    virtual ~Base() = default;
    virtual void Act() const {
        std::cout << "Base::Act" << std::endl;
    }
};

struct DerivedA : public Base {
    void Act() const override final {
        std::cout << "DerivedA::Act" << std::endl;
    }
};

struct DerivedB : public Base {
    void Act() const override final {
        std::cout << "DerivedB::Act" << std::endl;
    }
};

int main() {
    try {
        DerivedA d;
        throw d;
    } catch (const DerivedB& db) {
        std::cout << "Got derivedB" << std::endl;
        db.Act();
    } catch (const Base& b) {
        std::cout << "Got base" << std::endl;
        b.Act();
    }

    try {
        try {
            DerivedA d;
            throw d;
        } catch (const Base& b) {
            std::cout << "Got base internal" << std::endl;
            b.Act();
            throw b;
            // throw;
        }
    } catch (const Base& b) {
        std::cout << "Got base external" << std::endl;
        b.Act();
    }

    return 0;
}
