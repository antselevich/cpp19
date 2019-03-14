#pragma once

class Figure {
public:
    virtual ~Figure() = default;

    virtual double Area() const = 0;
    virtual void Scale(const double factor) = 0;
};
