#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include "circle.h"
#include "rectangle.h"
#include "util.h"

double rectangles[5][2] = {
  {1.0, 2.0},
  {2.0, 4.0},
  {3.0, 6.0},
  {4.0, 8.0},
  {5.0, 10.0},
};

double total_area(struct figure *const figures[],
                  size_t size) {
  double rv = 0.0;
  for (size_t i = 0; i != size; ++i)
    rv += figure_area(figures[i]);
  return rv;
}

void scale_all(struct figure *figures[], size_t size,
               double factor) {
  for (size_t i = 0; i != size; ++i)
    scale_figure(figures[i], factor);
}

int main(void) {
  char circle_memory[circle_size()];
  struct figure *all_figures[1 + ARRAYSIZE(rectangles)];
  all_figures[0] = init_circle(
      &circle_memory, sqrt(1.0 / M_PI));

  char *rectangle_memory = malloc(
      ARRAYSIZE(rectangles) * sizeof(struct figure *) +
      rectangle_size() * ARRAYSIZE(rectangles));

  FOREACH(i, rectangles) {
    all_figures[1 + i] = init_rectangle(
      rectangle_memory + i * rectangle_size(),
      rectangles[i][0], rectangles[i][1]);
  }

  printf("%lf\n", total_area(
    all_figures, ARRAYSIZE(all_figures)));

  scale_all(all_figures, ARRAYSIZE(all_figures), 2.0);

  printf("%lf\n", total_area(
    all_figures, ARRAYSIZE(all_figures)));

  free(rectangle_memory);
}
