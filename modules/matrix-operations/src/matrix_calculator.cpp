// Copyright 2020 Golubev Vladislav

#include "include/matrix_calculator.h"
#include "include/matrix_operations.h"

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <string>
#include <sstream>

MatrixCalculator::MatrixCalculator() : message_("") {}

void MatrixCalculator::help(const char* appname, const char* message) {
  message_ =
    std::string(message) +
    "This is a matrix calculator application. \n\n" +
    "Please provide arguments in the following format:\n\n" +
    /*
    */
    "Where matrix elements are double-precision numbers, " +
    "and <operation> is one of '+', '-', '*', '=='. '!=' " +
    "'det', 'T', 'inv'.\n";
}

bool MatrixCalculator::validateNumberOfArguments(int argc,
  const char** argv) {
  if (argc == 1) {
    help(argv[0]);
    return false;
  } else if (argc != 10 && argc != 7 && argc != 5) {
    help(argv[0], "Should be 9 or 6 or 5 arguments!\n\n");
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
  if (strcmp(arg, "+") == 0) {
    op = '1';
  } else if (strcmp(arg, "-") == 0) {
    op = '2';
  } else if (strcmp(arg, "*") == 0) {
    op = '3';
  } else if (strcmp(arg, "==") == 0) {
    op = '5';
  } else if (strcmp(arg, "!=") == 0) {
    op = '6';
  } else if (strcmp(arg, "det") == 0) {
    op = '7';
  } else if (strcmp(arg, "T") == 0) {
    op = '8';
  } else if (strcmp(arg, "inv") == 0) {
    op = '9';
  } else {
    throw std::string("Wrong operation format!");
  }
  return op;
}
