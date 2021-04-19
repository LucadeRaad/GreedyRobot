// Copyright 2020 Luca de Raad

#include "point.h"

#include <iostream>

Point::Point() {
    x_ = 0;
    y_ = 0;
}

Point::Point(int x, int y) {
    x_ = x;
    y_ = y;
}

int Point::get_x() const {
    return x_;
}

int Point::get_y() const {
    return y_;
}

// Creates a new point that has moved by the coordinate.
Point Point::move(Coordinates coordinates) const {
    Point output(x_, y_);
    switch (coordinates) {
    case N:
        output.y_++;
        break;
    case E:
        output.x_++;
        break;
    case S:
        output.y_--;
        break;
    case W:
        output.x_--;
        break;
    }
    return output;
}

bool Point::operator==(const Point& point) const {
    return (x_ == point.x_) &&
           (y_ == point.y_);
}
