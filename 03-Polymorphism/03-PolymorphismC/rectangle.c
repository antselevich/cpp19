#include <stddef.h>

#include "figure_impl.h"
#include "rectangle.h"
#include "util.h"

struct rectangle {
  struct figure base;
  double x;
  double y;
};


size_t rectangle_size(void) {
  return sizeof(struct rectangle);
}

double rectangle_area(const struct figure *f) {
  struct rectangle *c = DOWNCAST(struct rectangle, f);
  return c->x * c->y;
}

void scale_rectangle(struct figure *f,
                     const double factor) {
  struct rectangle *c = DOWNCAST(struct rectangle, f);
  c->x *= factor;
  c->y *= factor;
}

struct figure_ops rectangle_ops = {
  .area = rectangle_area,
  .scale = scale_rectangle,
};

struct figure *init_rectangle(void *memory,
                              double x, double y) {
  struct rectangle *rv = memory;
  rv->x = x;
  rv->y = y;
  rv->base.ops = &rectangle_ops;
  return UPCAST(struct rectangle, struct figure, rv);
}
