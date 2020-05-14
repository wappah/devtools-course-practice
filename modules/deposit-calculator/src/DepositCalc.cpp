// Copyright 2020 Mikhail Zakharov

#include "include/DepositCalc.h"
#include <iostream>

const unsigned int max_period_days = 1826;

DepositCalc::DepositCalc(const unsigned int& _depositAmount,
  const unsigned int& _period, const unsigned int& _rate)
    :depositAmount(_depositAmount), period(_period), rate(_rate) {}

unsigned int DepositCalc::getDepositAmount() const {
    return depositAmount;
}

unsigned int DepositCalc::getPeriod() const {
    return period;
}

unsigned int DepositCalc::getRate() const {
    return rate;
}

unsigned int DepositCalc::getDepositWithRate() const {
    return depositWithRate;
}

unsigned int DepositCalc::getInterestCharges() const {
    return interestCharges;
}

void DepositCalc::setDepositAmount(const unsigned int& depositAmount) {
    if (depositAmount < 1000)
        throw "Deposit amount must be >= 1000";
    this->depositAmount = depositAmount;
}

void DepositCalc::setPeriod(const unsigned int& period) {
    if (period == 0)
        throw "Period must be > 0";
    if (period > max_period_days)
        throw "Period must be < 1827";
    this->period = period;
}

void DepositCalc::setRate(const unsigned int& rate) {
    if (rate == 0)
        throw "Rate must be > 0";
    this->rate = rate;
}

void DepositCalc::calc() {
  double period_in_years = static_cast<double>(period) / 366;
  double interest_rate = static_cast<double>(rate) / 100;
  depositWithRate = depositAmount +
    depositAmount * period_in_years * interest_rate;
    interestCharges = depositWithRate - depositAmount;
}
