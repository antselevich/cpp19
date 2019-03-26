#pragma once

struct Obj {
    Obj() : val(0)
    {}
    void SetVar(int _val) const {
        val = _val;
    }

    mutable int val;
};

const Obj obj;
