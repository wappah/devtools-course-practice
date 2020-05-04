// Copyright 2020 Sokolov Andrey

#ifndef MODULES_DISTANCE_BETWEEN_VECTORS_INCLUDE_DISTANCE_CALCULATOR_H_
#define MODULES_DISTANCE_BETWEEN_VECTORS_INCLUDE_DISTANCE_CALCULATOR_H_

#include <string>

class DistanceCalculator {
 public:
    DistanceCalculator();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        double x1;
        double y1;
        double z1;
        double x2;
        double y2;
        double z2;
        char operation;
    } Arguments;
};

#endif  // MODULES_DISTANCE_BETWEEN_VECTORS_INCLUDE_DISTANCE_CALCULATOR_H_
