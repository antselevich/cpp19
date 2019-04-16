#include <iostream>

struct A {
    A() : state(0) {
        std::cout << "A constructed" << std::endl;
    }

    A(const A& a) : state(a.state) {
        std::cout << "A copied" << std::endl;
    }

    ~A() {
        std::cout << "A destroyed; state was " << state << std::endl;
    }

    void changeState(int newState) {
        state = newState;
    }

    int state;
};

A getA() {
    std::cout << "run getA" << std::endl;
    return A();
}

int main() {
    try {
        std::cout << "try start" << std::endl;
        throw getA();
    } catch (A& a) {
    // } catch (A a) {
    // } catch (const A& a) {
    // } catch (A&& a) {
        std::cout << "catch start" << std::endl;
        a.changeState(1);
        std::cout << "catch end" << std::endl;
    }
    std::cout << "after try" << std::endl;

    return 0;
}
