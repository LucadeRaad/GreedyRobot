// Copyright 2020 Luca de Raad

#include "robot.h"
#include "point.h"
#include <string>
#include <iostream>

Robot::Robot(Point start, Point target, int max_distance) {
    max_distance_ = max_distance;
    path_count_ = 0;
}

// We find the directions the robot took. The robot cannot go the same
// direction for more than "max_distance_"
// Returns true if the coordinate is valid for the path
bool Robot::PathCheck(std::string path, char coordinate) {
    if (path.size() < max_distance_) {
        return true;
    }

    std::string compare = path.substr(path.size() - max_distance_);
    int count = 0;

    for (int i = 0; i < compare.size(); i++) {
        if (compare.at(i) == coordinate) {
            count++;
        }
    }
    return count != max_distance_;
}

// Recursive. From a location, starts every possible towards the target.
// Stores the path taken to the target and how many viable paths.
void Robot::NumPaths(Point location, Point target, std::string path) {
    if (location == target) {
        std::cout << path << std::endl;
        path_count_++;
        return;
    }

    // Checks to see what direction the robot can go and recurses.
    if ((target.get_y() > location.get_y()) &&
        PathCheck(path, CoordinateNames[Coordinates::N])) {
        std::string new_path = path + CoordinateNames[Coordinates::N];
        NumPaths(location.move(Coordinates::N), target, new_path);
    }

    if ((target.get_x() > location.get_x()) &&
        PathCheck(path, CoordinateNames[Coordinates::E])) {
        std::string new_path = path + CoordinateNames[Coordinates::E];
        NumPaths(location.move(Coordinates::E), target, new_path);
    }

    if ((target.get_y() < location.get_y()) &&
        PathCheck(path, CoordinateNames[Coordinates::S])) {
        std::string new_path = path + CoordinateNames[Coordinates::S];
        NumPaths(location.move(Coordinates::S), target, new_path);
    }

    if ((target.get_x() < location.get_x()) &&
        PathCheck(path, CoordinateNames[Coordinates::W])) {
        std::string new_path = path + CoordinateNames[Coordinates::W];
        NumPaths(location.move(Coordinates::W), target, new_path);
    }
}
