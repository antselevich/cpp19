#pragma once

#include "figure.h"

#include <stddef.h>

class Rectangle final : public Figure {
public:
    Rectangle(double x, double y) : X(x), Y(y) {
    }

    double Area() const override final;
    void Scale(const double factor) override final;

private:
    double X;
    double Y;
};
