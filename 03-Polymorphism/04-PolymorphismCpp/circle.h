#pragma once

#include "figure.h"

#include <stddef.h>

class Circle final : public Figure {
public:
    Circle(double radius) : Radius(radius) {
    }

    double Area() const override final;
    void Scale(const double factor) override final;

private:
    double Radius;
};
