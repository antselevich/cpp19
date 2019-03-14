#include "vector_capacity.h"

#include <assert.h>
#include <iostream>

size_t Vector::Multiplier = 2;

int main(void) {
    assert(1 == Vector::CalcNewCapacity(0, 1));
    assert(6 == Vector::CalcNewCapacity(3, 4));
    assert(7 <= Vector::CalcNewCapacity(2, 7));

	// Vector v();
	Vector v;
	assert(v.Resize(20));

	for (size_t i = 0; i < v.Size(); ++i) {
		v.SetElem(i, (int)(i + 5));
  	}

	assert(v.PushBack(99));

	for (size_t i = v.Size(); i > 0; --i) {
    	std::cout << v.GetElem(i - 1) << ", ";
  	}
	std::cout << std::endl;
}
