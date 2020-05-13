// Copyright 2020 Kornev Nikita

#ifndef MODULES_DEPOSIT_CALCULATOR_INCLUDE_DEPOSITCALC_APP_H_
#define MODULES_DEPOSIT_CALCULATOR_INCLUDE_DEPOSITCALC_APP_H_

#include <string>
#include <utility>
#include <vector>

class DepositCalc_app {
public:
    DepositCalc_app();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
      int depositAmount;
      unsigned int period;
      int rate;
    } Arguments;
};

#endif  // MODULES_DEPOSIT_CALCULATOR_INCLUDE_DEPOSITCALC_APP_H_
