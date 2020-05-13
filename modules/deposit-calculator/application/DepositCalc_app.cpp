// Copyright 2020 Kornev Nikita

#include <iostream>
#include <string>

#include "include/DepositCalc_app.h"

int main(int argc, const char** argv) {
    Deostring output = app(argc, argv);
    std::cout << output << std::endl;
    return 0;
}
