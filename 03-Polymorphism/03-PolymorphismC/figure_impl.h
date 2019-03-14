#pragma once

#include "figure.h"

struct figure_ops;

struct figure {
  const struct figure_ops *ops;
};

struct figure_ops {
  double (*area)(const struct figure *);
  void (*scale)(struct figure *, const double factor);
};
