#pragma once

#include <stdbool.h>
#include <stdlib.h>

struct Vector {
  size_t size;
  size_t capacity;
  int* data;
};

struct Vector empty_vector();
void free_vector(struct Vector *v);

bool resize_vector(struct Vector *v, size_t new_size);
size_t size_vector(const struct Vector *v);

int get_elem_vector(const struct Vector *v, size_t index);
void set_elem_vector(struct Vector *v, size_t index, int elem);
bool push_back_vector(struct Vector *v, int elem);

size_t calc_new_capacity(size_t current_capacity, size_t new_size);
