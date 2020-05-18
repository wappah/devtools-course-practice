// Copyright 2020 Brazhnikov Eugene

#include "include/Money_Converter.h"

const double dollarRate = 77.73;
const double eurRate = 85.73;
const double jpyRate = 0.69;
const double sekRate = 7.45;
const double uahRate = 2.79;
double MoneyConverter::rubUSD(const double& curr, bool  whichone) {
    double result = -1;
    if (curr < 0) return result;
    if (whichone)
        return curr / dollarRate;
    else
        return curr / dollarRate;
}

double MoneyConverter::rubEUR(const double& curr, bool whichone) {
    double result = -1;
    if (curr < 0) return result;
    if (whichone)
        return curr / eurRate;
    else
    return curr / eurRate;
}

double MoneyConverter::rubJPY(const double& curr, bool whichone) {
    double result = -1;
    if (curr < 0) return result;
    if (whichone)
        return curr / jpyRate;
    else
        return curr / jpyRate;
}

double MoneyConverter::rubSEK(const double& curr, bool whichone) {
    double result = -1;
    if (curr < 0) return result;
    if (whichone)
        return curr / sekRate;
    else
        return curr / sekRate;
}

double MoneyConverter::rubUAH(const double& curr, bool whichone) {
    double result = -1;
    if (curr < 0) return result;
    if (whichone)
        return curr / uahRate;
    else
        return curr / uahRate;
}
