// Copyright 2020 Golubev Vladislav

#include "include/matrix_calculator.h"
#include "include/matrix_operations.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <vector>
#include <string>
#include <sstream>

MatrixCalculator::MatrixCalculator() : message_("") {}

void MatrixCalculator::help(const char* appname, const char* message) {
  message_ =
    std::string(message) +
    "This is a matrix calculator application. \n\n" +
    "Please provide arguments in the following format:\n\n" +

    "Where matrix elements are double-precision numbers, " +
    "and <operation> is one of '+', '-', '*', '=='. '!=' " +
    "'det', 'T', 'inv'.\n";
}

bool MatrixCalculator::validateNumberOfArguments(int argc,
  const char** argv) {
  if (argc == 1) {
    help(argv[0]);
    return false;
  } else if (argc != 10 && argc != 7 && argc != 6) {
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

std::vector<double> MatrixCalculator::pushA(int argc,
  const char** argv) {
  std::vector<double> res(4);

  res.push_back(parseDouble(argv[1]));
  res.push_back(parseDouble(argv[2]));
  res.push_back(parseDouble(argv[3]));
  res.push_back(parseDouble(argv[4]));

  return res;
}
std::vector<double> MatrixCalculator::pushB(int argc,
  const char** argv) {
  std::vector<double> res(4);

  res.push_back(parseDouble(argv[5]));
  res.push_back(parseDouble(argv[6]));
  res.push_back(parseDouble(argv[7]));
  res.push_back(parseDouble(argv[8]));

  return res;
}

std::string MatrixCalculator::operator()(int argc, const char** argv) {
  Arguments args;

  if (!validateNumberOfArguments(argc, argv)) {
    return message_;
  }
  try {
    args.a = pushA(argc, argv);
    if (argc == 10) {
      args.b = pushB(argc, argv);
      args.operation = parseOperation(argv[9]);
    } else if (argc == 7) {
      args.ñ = parseDouble(argv[5]);
      args.operation = parseOperation(argv[6]);
    } else {
      args.operation = parseOperation(argv[5]);
    }
  }
  catch (std::string & str) {
    return str;
  }

  Matrix lhs(2, 2);
  Matrix rhs(2, 2);
  Matrix resMatrix(2, 2);
  bool resBool;
  double scalar = args.ñ;
  std::ostringstream stream;

  switch (args.operation) {
  case '1':
    resMatrix = lhs + rhs;
    stream << "A + B = ";
    break;
  case '2':
    resMatrix = lhs - rhs;
    stream << "A - B = ";
    break;
  case '3':
    if (argc == 10) {
      resMatrix = lhs * scalar;
      stream << "c * A = ";
    } else {
      resMatrix = lhs * rhs;
      stream << "A * B = ";
    }
    break;
  case '5':
    resBool = lhs == rhs;
    stream << "A == B: " << resBool;
    break;
  case '6':
    resBool = lhs != rhs;
    stream << "A != B: " << resBool;
    break;
  case '7':
    stream << "det(A) = " << lhs.determinant();
    break;
  case '8':
    resMatrix = lhs.transpose();
    stream << "A.T = ";
    break;
  case '9':
    resMatrix = lhs.takeInverseMatrix();
    stream << "A^(-1)";
    break;
  }

  message_ = stream.str();
  return message_;
}
