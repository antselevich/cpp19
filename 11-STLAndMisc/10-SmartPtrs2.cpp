#include <iostream>
#include <memory>

struct A {
public:
    A(int x) : x(x) {
        std::cout << "A constructed " << x << std::endl;
    }

    ~A() {
        std::cout << "A destructed" << std::endl;
    }

    void Act() const {
        std::cout << "Act " << x << std::endl;
    }

private:
    int x;
};

struct Employee {
    // std::shared_ptr<Employee> relative;

    std::shared_ptr<Employee> father;
    std::weak_ptr<Employee> son;
};

int main() {
    {
        std::shared_ptr<A> ptrA(new A(5));
        std::cout << "Use count: " << ptrA.use_count() << std::endl;
        std::shared_ptr<A> ptrB = ptrA;
        std::cout << "Use count: " << ptrA.use_count()
                           << ", " << ptrB.use_count() << std::endl;
        std::shared_ptr<A> ptrC(ptrA);
        std::cout << "Use count: " << ptrA.use_count()
                           << ", " << ptrB.use_count()
                           << ", " << ptrC.use_count() << std::endl;
        ptrB.reset();
        std::cout << "Use count: " << ptrA.use_count()
                           << ", " << ptrB.use_count()
                           << ", " << ptrC.use_count() << std::endl;
    }

    {
        // // Circular pointers, memory leak:
        // Employee* john = new Employee();
        // Employee* michael = new Employee();
        // john->relative.reset(michael);
        // michael->relative.reset(john);

        auto michael = std::make_shared<Employee>();
        auto john = std::make_shared<Employee>();
        john->father = michael;
        michael->son = john;

        if (auto michaelsSon = michael->son.lock()) {
            // ...
        }
    }
}
