// Copyright 2020 Sokolov Andrey

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/distance_calculator.h"

int main(int argc, const char** argv) {
    DistanceCalculator app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
