#include <iostream>
#include <sstream>
#include <string>

struct Employee {
    Employee(const char* name, unsigned short age)
        : name(name), age(age) { }

    std::string toString() const {
        // return "Employee " + name + " of age " + std::to_string(age); // won't compile
        // return std::string("Employee ") + name + " of age " + std::to_string(age);

        std::stringstream result;
        result << "Employee " << name << " of age " << age;
        return result.str();
    }

    const char* name;
    unsigned short age;
};

int main() {
    Employee a1("Andrew", 26);
    std::cout << a1.toString() << std::endl;
}
