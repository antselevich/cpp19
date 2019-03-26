#include "unit1.h"

#include "obj.h"

void Set1Var(int a) {
    obj.SetVar(a);
}
int Get1Var() {
    return obj.val;
}
const void* Get1Addr() {
    return &obj;
}
