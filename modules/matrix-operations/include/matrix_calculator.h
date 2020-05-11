// Copyright 2020 Golubev Vlad
#ifndef MODULES_MATRIX_OPERATIONS_INCLUDE_MATRIX_CALCULATOR_H_
#define MODULES_MATRIX_OPERATIONS_INCLUDE_MATRIX_CALCULATOR_H_

#include <string>

class MatrixCalculator {
 public:
   MatrixCalculator();
   std::string operator()(int argc, const char** argv);

 private:
   void help(const char* appname, const char* message = "");
   bool validateNumberOfArguments(int argc, const char** argv);
   std::string message_;
   typedef struct {
     double _zero;
   } Arguments;
};

#endif  // MODULES_MATRIX_OPERATIONS_INCLUDE_MATRIX_OPERATIONS_APP_H_
