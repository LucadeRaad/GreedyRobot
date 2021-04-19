// Copyright 2020 Luca de Raad

// Point holds an x,y and moves points
#ifndef POINT_H_
#define POINT_H_

#include <utility>

enum Coordinates { N, E, S, W };
static char CoordinateNames[] { 'N', 'E', 'S', 'W' };

class Point {
 public:
    Point();
    Point(int x, int y);

    int get_x() const;
    int get_y() const;

    Point move(Coordinates coordinates) const;

    bool operator==(const Point& point) const;

 private:
    int x_;
    int y_;
};

#endif  // POINT_H_
