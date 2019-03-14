#include "vector_capacity.h"

#include <assert.h>
#include <stdio.h>

size_t multiplier = 2;

int main(void) {
  assert(1 == calc_new_capacity(0, 1));
  assert(6 == calc_new_capacity(3, 4));
  assert(7 <= calc_new_capacity(2, 7));

  struct Vector v = empty_vector();
  assert(resize_vector(&v, 20));

  for (size_t i = 0; i < size_vector(&v); ++i) {
    set_elem_vector(&v, i, i + 5);
  }

  assert(push_back_vector(&v, 99));

  for (int i = size_vector(&v) - 1; i >= 0; --i) {
    printf("%d, ", get_elem_vector(&v, i));
  }

  printf("\n");

  free_vector(&v);
}
