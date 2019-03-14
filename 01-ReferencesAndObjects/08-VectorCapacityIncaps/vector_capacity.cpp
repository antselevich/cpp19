#include "vector_capacity.h"

#include <iostream>
#include <stdlib.h>

Vector::Vector()
    : Size_(0)
    , Capacity(0)
    , Data(nullptr)
{
    // std::cout << "Constructor called" << std::endl;
}

Vector::~Vector() {
    // std::cout << "Destructor called" << std::endl;
    if (Data) {
        free(Data);
    }
}

bool Vector::Resize(size_t newSize) {
	if (newSize > Capacity) {
		if (!Realloc(newSize)) {
			return false;
        }
    }

    for (size_t i = Size_; i < newSize; ++i) {
        SetElem(i, 0);
    }

    Size_ = newSize;
    return true;
}

size_t Vector::Size() const {
    return Size_;
}

int Vector::GetElem(size_t index) const {
    return Data[index];
}

void Vector::SetElem(size_t index, int elem) {
    Data[index] = elem;
}

bool Vector::PushBack(int elem) {
	if (Size_ == Capacity) {
		if (!Realloc(Size_ + 1)) {
			return false;
		}
    }

    Data[Size_] = elem;
    ++Size_;

    return true;
}

size_t Vector::CalcNewCapacity(
    size_t currentCapacity,
    size_t newSize)
{
    size_t newCapacity = currentCapacity
        ? currentCapacity
        : 1;

    while (newCapacity < newSize) {
        newCapacity *= Multiplier;
    }

    return newCapacity;
}

bool Vector::Realloc(size_t newSize) {
    if (newSize == 0) {
        return true;
    }

    const size_t newCapacity = CalcNewCapacity(Capacity, newSize);

    Data = (int *)realloc(Data, newCapacity * sizeof(int));

    if (!Data) {
        return false;
    }

    Capacity = newCapacity;
    return true;
}
