#include <stddef.h>
#include <math.h>

#include "circle.h"


double Circle::Area() const {
    return M_PI * Radius * Radius;
}

void Circle::Scale(double factor) {
    Radius *= factor;
}
