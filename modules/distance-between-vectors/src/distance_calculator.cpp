// Copyright 2020 Sokolov Andrey

#include "include/distance_calculator.h"
#include "include/distance_between_vectors.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <vector>
#include <string>
#include <sstream>

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
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

char parseOperation(const char* arg) {
    char op;
    if (strcmp(arg, "L1") == 0) {
        op = '1';
    } else if (strcmp(arg, "L2") == 0) {
        op = '2';
    } else if (strcmp(arg, "L3") == 0) {
        op = '3';
    } else if (strcmp(arg, "L4") == 0) {
        op = '4';
    } else if (strcmp(arg, "LInf") == 0) {
        op = 'I';
    } else {
        throw std::string("Wrong operation format!");
    }
    return op;
}

std::string DistanceCalculator::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.x1 = parseDouble(argv[1]);
        args.y1 = parseDouble(argv[2]);
        args.z1 = parseDouble(argv[3]);
        args.x2 = parseDouble(argv[4]);
        args.y2 = parseDouble(argv[5]);
        args.z2 = parseDouble(argv[6]);
        args.operation = parseOperation(argv[7]);
    }
    catch(std::string& str) {
        return str;
    }

    std::vector<float> fst;
    std::vector<float> sec;

    fst.push_back(args.x1);
    fst.push_back(args.y1);
    fst.push_back(args.z1);
    sec.push_back(args.x2);
    sec.push_back(args.y2);
    sec.push_back(args.z2);

    Metrics metrics(fst, sec);
    double res;
    std::ostringstream stream;

    switch (args.operation) {
     case '1':
        res = metrics.getL1();
        stream << "L1 = " << res;
        break;
     case '2':
        res = metrics.getL2();
        stream << "L2 = " << res;
        break;
     case '3':
        res = metrics.getL3();
        stream << "L3 = " << res;
        break;
     case '4':
         res = metrics.getL4();
         stream << "L4 = " << res;
         break;
     case 'I':
         res = metrics.getLInf();
         stream << "LInf = " << res;
         break;
    }

    message_ = stream.str();

    return message_;
}
