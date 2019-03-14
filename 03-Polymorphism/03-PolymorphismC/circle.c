#include <stddef.h>
#include <math.h>

#include "circle.h"
#include "figure_impl.h"
#include "util.h"

struct circle {
  struct figure base;
  double radius;
};

size_t circle_size(void) {
  return sizeof(struct circle);
}

double circle_area(const struct figure *f) {
  struct circle *c = DOWNCAST(struct circle, f);
  return M_PI * c->radius * c->radius;
}

void scale_circle(struct figure *f,
                  const double factor) {
  struct circle *c = DOWNCAST(struct circle, f);
  c->radius *= factor;
}

struct figure_ops circle_ops = {
  .area = circle_area,
  .scale = scale_circle,
};

struct figure *init_circle(void *memory, double radius) {
  struct circle *rv = memory;
  rv->radius = radius;
  rv->base.ops = &circle_ops;
  return UPCAST(struct circle, struct figure, rv);
}
