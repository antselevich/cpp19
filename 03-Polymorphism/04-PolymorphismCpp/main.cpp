#include <math.h>
#include <stdlib.h>
#include <iostream>

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

double totalArea(Figure *const figures[], size_t size) {
    double rv = 0.0;
    for (size_t i = 0; i < size; ++i) {
        rv += figures[i]->Area();
    }
    return rv;
}

void scaleAll(Figure *figures[], size_t size, double factor) {
    for (size_t i = 0; i < size; ++i) {
        figures[i]->Scale(factor);
    }
}

int main() {
    Figure* allFigures[1 + ARRAYSIZE(rectangles)];

    allFigures[0] = new Circle(sqrt(1.0 / M_PI));

    for (size_t i = 0; i < ARRAYSIZE(rectangles); ++i) {
        allFigures[1 + i] = new Rectangle(rectangles[i][0], rectangles[i][1]);
    }

    std::cout << totalArea(allFigures, ARRAYSIZE(allFigures)) << std::endl;
    scaleAll(allFigures, ARRAYSIZE(allFigures), 2.0);
    std::cout << totalArea(allFigures, ARRAYSIZE(allFigures)) << std::endl;

    for (size_t i = 0; i < ARRAYSIZE(allFigures); ++i) {
        delete allFigures[i];
    }

    return 0;
}
