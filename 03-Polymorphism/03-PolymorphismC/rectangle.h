#pragma once

#include "figure.h"

#include <stddef.h>

size_t rectangle_size(void);
struct figure *init_rectangle(void *memory,
                              double x, double y);
