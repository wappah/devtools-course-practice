// Copyright 2020 Sokolov Andrey

#ifndef MODULES_DISTANCE_BETWEEN_VECTORS_INCLUDE_DISTANCE_CALCULATOR_H_
#define MODULES_DISTANCE_BETWEEN_VECTORS_INCLUDE_DISTANCE_CALCULATOR_H_

#include <string>
#include <vector>

class DistanceCalculator {
 public:
    DistanceCalculator();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        std::vector<float> vectorA;
        std::vector<float> vectorB;
        char operation;
    } Arguments;
};

#endif  // MODULES_DISTANCE_BETWEEN_VECTORS_INCLUDE_DISTANCE_CALCULATOR_H_
