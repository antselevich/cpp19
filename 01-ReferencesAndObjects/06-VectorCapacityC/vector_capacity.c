#include "vector_capacity.h"

struct Vector empty_vector() {
  struct Vector v;
  v.size = 0;
  v.capacity = 0;
  v.data = NULL;
  return v;
}

void free_vector(struct Vector *v) {
  v->size = 0;
  v->capacity = 0;

  if (v->data) {
    free(v->data);
    v->data = NULL;
  }
}

static bool realloc_vector(struct Vector* v, size_t new_size) {
  if (new_size == 0)
    return true;

  const size_t new_capacity = calc_new_capacity(v->capacity, new_size);

  v->data = realloc(v->data, new_capacity * sizeof(int));

  if (!v->data)
    return false;

  v->capacity = new_capacity;

  return true;
}

bool resize_vector(struct Vector *v, size_t new_size) {
  if (new_size > v->capacity) {
    if (!realloc_vector(v, new_size)) {
      return false;
    }
  }

  for (size_t i = v->size; i < new_size; ++i) {
    set_elem_vector(v, i, 0);
  }

  v->size = new_size;

  return true;
}

size_t size_vector(const struct Vector *v) {
  return v->size;
}

int get_elem_vector(const struct Vector *v, size_t index) {
  return v->data[index];
}

void set_elem_vector(struct Vector *v, size_t index, int elem) {
  v->data[index] = elem;
}

bool push_back_vector(struct Vector *v, int elem) {
  if (v->size == v->capacity)
    if (!realloc_vector(v, v->size + 1))
      return false;

  v->data[v->size] = elem;
  ++v->size;

  return true;
}

extern size_t multiplier;

size_t calc_new_capacity(size_t current_capacity, size_t new_size) {
  size_t new_capacity = current_capacity
    ? current_capacity
    : 1;

  while (new_capacity < new_size)
    new_capacity *= multiplier;

  return new_capacity;
}
