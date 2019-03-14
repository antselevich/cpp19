#include <stddef.h>

#include "rectangle.h"

double Rectangle::Area() const {
    return X * Y;
}

void Rectangle::Scale(double factor) {
    X *= factor;
    Y *= factor;
}
