// Copyright 2020 Sokova Anastasia

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/money_converter_app.h"

int main(int argc, const char** argv) {
    MoneyCalculator app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
