#include <iostream>

namespace ns {
    struct NSType {
        int a;
    };
    void NSFunc(const NSType& a) {
        std::cout << "ns::NSFunc(const NSType&), a.a = " << a.a << std::endl;
    }
    void SimpleFunc( int x ) {
        std::cout << "ns::simpleFunc(" << x << ")" << std::endl;
    }
}

struct Type {
    int a;
};
void NSFunc( const Type& a ) {
    std::cout << "NSFunc(const Type&), a.a = " << a.a << std::endl;
}
void SimpleFunc( int x ) {
    std::cout << "ns::SimpleFunc(" << x << ")" << std::endl;
}

int main() {
    Type t {1};
    ns::NSType nt {2};
    NSFunc(t);
    NSFunc(nt);
    SimpleFunc(3);

    return 0;
}