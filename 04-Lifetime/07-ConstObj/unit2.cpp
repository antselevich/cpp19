#include "unit2.h"

#include "obj.h"

void Set2Var(int a) {
    obj.SetVar(a);
}
int Get2Var() {
    return obj.val;
}
const void* Get2Addr() {
    return &obj;
}
