#include <iostream>

#include <vector>
#include <list>

template <class T>
struct ContainerResolve {
    static void action() {
        std::cout << "generic type, no info about element" << std::endl;
    }
};
// struct ContainerResolve;

template <class T>
struct ContainerResolve<std::vector<T>> {
    static void action() {
        std::cout << "vector, element size: " 
        << sizeof(T) << std::endl;
    }
};

template <class T>
struct ContainerResolve<std::list<T>> {
    static void action() {
        std::cout << "list, element size: " 
        << sizeof(T) << std::endl;
    }
};

int main() {
    ContainerResolve<int>::action();
    ContainerResolve<std::vector<int>>::action();
    ContainerResolve<std::vector<std::vector<int>>>::action();
    ContainerResolve<std::list<int>>::action();

    return 0;
}