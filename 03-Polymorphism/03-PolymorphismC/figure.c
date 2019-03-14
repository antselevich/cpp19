#include "figure_impl.h"

double figure_area(struct figure *f) {
  return f->ops->area(f);
}

void scale_figure(struct figure *f, const double factor) {
  f->ops->scale(f, factor);
}
