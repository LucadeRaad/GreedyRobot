// Copyright 2020 Luca de Raad

// The robot code holds the greedy robot algorithm that finds the fastest paths
// from the current location to the target with constraints. It also needs to print out 
// every possible fastest path.

#ifndef ROBOT_H_
#define ROBOT_H_

#include <string>

#include "point.h"

class Robot {
 public:
    Robot(Point start, Point target, int max_distance);

    void NumPaths(const Point location,
                  const Point target,
                  const std::string path);

    int path_count_;

 private:
    int max_distance_;

    bool PathCheck(const std::string path, const char coordinate);
};

#endif  // ROBOT_H_
