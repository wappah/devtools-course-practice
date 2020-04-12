// Copyright 2020 Petrov Anton

#include "include/MortgageCalc.h"
#include <cmath>
#include <iostream>

MortgageCalc::MortgageCalc(int _cost, int _downPayment,
    int _creditTerm, double _interestRate) :cost(_cost),
    downPayment(_downPayment), creditTerm(_creditTerm),
    interestRate(_interestRate) {}

int MortgageCalc::getCost() {
    return cost;
}

int MortgageCalc::getDownPayment() {
    return downPayment;
}

int MortgageCalc::getCreditTerm() {
    return creditTerm;
}

double MortgageCalc::getInterestRate() {
    return interestRate;
}

int MortgageCalc::getTotalFee() {
    return totalFee;
}

double MortgageCalc::getMonthlyRate() {
    return monthlyRate;
}

int MortgageCalc::getMonthlyPayment() {
    return monthlyPayment;
}

void MortgageCalc::setCost(const int& cost) {
    this->cost = cost;
}

void MortgageCalc::setDownPayment(const int& downPayment) {
    this->downPayment = downPayment;
}

void MortgageCalc::setCreditTerm(const int& creditTerm) {
    this->creditTerm = creditTerm;
}

void MortgageCalc::setInterestRate(const double& interestRate) {
    this->interestRate = interestRate;
}

void MortgageCalc::calc() {
    cost -= downPayment;
    creditTerm *= 12;
    monthlyRate = ((interestRate) / 100) / 12;
    double tmp;
    tmp = pow((1 + monthlyRate), creditTerm);
    monthlyPayment = cost * monthlyRate * (tmp / (tmp - 1));
    totalFee = monthlyPayment * creditTerm;
}
