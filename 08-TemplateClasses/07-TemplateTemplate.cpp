#include <iostream>

#include <vector>
#include <list>

template <class T, template <class> class Cont>
class Storage {
    struct Val {
        int num;
        T val;
    };
public:
    void add(T val) {
        data.push_back(Val{num++, val});
    }
    T backVal() const {
        return data.back().val;
    }
    int backId() const {
        return data.back().num;
    }
    void pop() {
        data.pop_back();
    }
private:
    int num = 0;
    Cont<Val> data;
};

template <class T>
using TList = std::list<T>;

template <class T>
using TVector = std::vector<T>;

int main() {
    Storage<float, TList> lStor;

    lStor.add(0.2f);
    lStor.add(0.5f);
    std::cout << "lStor, val " << lStor.backVal() << " id " << lStor.backId() << std::endl;
    lStor.pop();
    std::cout << "lStor, val " << lStor.backVal() << " id " << lStor.backId() << std::endl;

    Storage<float, TVector> vStor;
    vStor.add(0.2f);
    vStor.add(0.5f);
    std::cout << "vStor, val " << vStor.backVal() << " id " << vStor.backId() << std::endl;
    vStor.pop();
    std::cout << "vStor, val " << vStor.backVal() << " id " << vStor.backId() << std::endl;

    return 0;
}