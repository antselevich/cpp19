#include <iostream>

int SumRecursive() {
    return 0;
}

template <class... Args>
int SumRecursive(int head, Args&&... tail) {
    return head + SumRecursive(std::forward<Args>(tail)...);
}

template <class... Args>
int SumFold(Args&&... elems) {
    // return (... + elems);
    return (0 + ... + elems);
}

template <class T>
T WithSpace(T arg) {
    std::cout << ' ';
    return arg;
}

template <class Head, class... Tail>
void BadPrintOrNot(Head head, Tail... tail) {
    std::cout << head;
    (std::cout << ... << WithSpace(tail));
    std::cout << std::endl;
}

/*
1) Unary right fold (E op ...) becomes (E[1] op (... op (E[N-1] op E[N])))
2) Unary left fold (... op E) becomes (((E[1] op E[2]) op ...) op E[N])
3) Binary right fold (E op ... op I) becomes (E[1] op (... op (E[N−1] op (E[N] op I))))
4) Binary left fold (I op ... op E) becomes ((((I op E[1]) op E[2]) op ...) op E[N])
*/

int main() {
    std::cout << SumRecursive(1, 10, 100, 1000) << std::endl;
    std::cout << SumFold(1, 10, 100, 1000) << std::endl;
    std::cout << SumFold() << std::endl;

    BadPrintOrNot(1, "ololo", 3.14f);
    return 0;
}
