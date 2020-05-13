// Copyright 2020 Sokolov Andrey

#include <vector>
#include <string>
#include <sstream>

#include "include/distance_calculator.h"
#include "include/distance_between_vectors.h"

DistanceCalculator::DistanceCalculator() : message_("") {}

void DistanceCalculator::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a distance between vectors calculator application.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          "$ " + appname + " <x1> <y1> <z1> " +
          "<x2> <y2> <z2> <metrics>\n\n" +

          "Where vector elements are double-precision numbers, " +
          "and <metrics> is one of 'L1', 'L2', 'L3', 'L4', 'LInf'.\n";
}

bool DistanceCalculator::validateNumberOfArguments(int          argc,
                                                   const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 8) {
        help(argv[0], "Should be 7 arguments!\n\n");
        return false;
    }
    return true;
}

double parseDouble(const char* arg) {
    double value;
    try {
        value = std::stod(arg);
    } catch (...) {
        throw std::string("Wrong number format!");
    }
    return value;
}

char parseOperation(const char* arg) {
    char operation;
    std::string notParsedOperation(arg);
    if (notParsedOperation == "L1") {
        operation = '1';
    } else if (notParsedOperation == "L2") {
        operation = '2';
    } else if (notParsedOperation == "L3") {
        operation = '3';
    } else if (notParsedOperation == "L4") {
        operation = '4';
    } else if (notParsedOperation == "LInf") {
        operation = 'I';
    } else {
        throw std::string("Wrong operation format!");
    }
    return operation;
}

std::string DistanceCalculator::operator()(int argc, const char** argv) {
    Arguments args;
    args.vectorA.resize(3, 0);
    args.vectorB.resize(3, 0);
    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.vectorA[0] = parseDouble(argv[1]);
        args.vectorA[1] = parseDouble(argv[2]);
        args.vectorA[2] = parseDouble(argv[3]);
        args.vectorB[0] = parseDouble(argv[4]);
        args.vectorB[1] = parseDouble(argv[5]);
        args.vectorB[2] = parseDouble(argv[6]);
        args.operation  = parseOperation(argv[7]);
    }
    catch(std::string& str) {
        return str;
    }

    std::ostringstream stream;
    Metrics metrics(args.vectorA, args.vectorB);

    switch (args.operation) {
     case '1':
        stream << "L1 = " << metrics.getL1();
        break;
     case '2':
        stream << "L2 = " << metrics.getL2();
        break;
     case '3':
        stream << "L3 = " << metrics.getL3();
        break;
     case '4':
         stream << "L4 = " << metrics.getL4();
         break;
     case 'I':
         stream << "LInf = " << metrics.getLInf();
         break;
    }

    message_ = stream.str();
    return message_;
}
