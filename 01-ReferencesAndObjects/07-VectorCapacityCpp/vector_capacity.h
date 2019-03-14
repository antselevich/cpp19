#pragma once

#include <stddef.h>

struct Vector {
    Vector();
    ~Vector();

    bool Resize(size_t newSize);
    size_t Size() const;
    int GetElem(size_t index) const;
    void SetElem(size_t index, int elem);
    bool PushBack(int elem);

    static size_t Multiplier;
    static size_t CalcNewCapacity(
        size_t currentCapacity,
        size_t newSize);

    bool Realloc(size_t newSize);

    size_t Size_;
    size_t Capacity;
    int *Data;
};
