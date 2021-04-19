// Copyright 2020 Luca de Raad

#include "point.h"
#include "robot.h"
#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc == 6) {
        int val = 0;
        int inputs[5];

        // Checking each input to see if they are ints
        for (int i = 1; i < 6; i++) {
            std::istringstream iss(argv[i]);
            // iostream::>> does two things- returns a boolean if conversion was successful and extracts int to "val"
            if (!(iss >> val)) {
                std::cerr << "Input must be an integer!" << std::endl;
                return 0;
            }
            // to fix off by one
            inputs[i - 1] = val;
        }

        if (inputs[4] < 0) {
            std::cerr << "Max Distance cannot be negative!" << std::endl;
            return 0;
        }

        Point start(inputs[0], inputs[1]);
        Point target(inputs[2], inputs[3]);

        if (start == target) {
            std::cout << "Start and target are the same!" << std::endl;
        } else {
            // Enumerate paths
            Robot my_robot = Robot(start, target, inputs[4]);

            my_robot.NumPaths(start, target, "");

            std::cout << "Number of paths: " << my_robot.path_count_ << std::endl;
        }
    } else {
        std::cerr << "Usage: GreedyRobot <x-start> <y-start> <x-goal> <y-goal> <max-repetition>" << std::endl;
    }
}
