// Copyright 2020 Mikhail Zakharov & Kornev Nikita

#ifndef MODULES_DEPOSIT_CALCULATOR_INCLUDE_DEPOSITCALC_H_
#define MODULES_DEPOSIT_CALCULATOR_INCLUDE_DEPOSITCALC_H_
extern const unsigned int max_period_days;

class DepositCalc {
    unsigned int depositAmount;
    unsigned int period;
    unsigned int rate;
    unsigned int depositWithRate;
    unsigned int interestCharges;
 public:
    DepositCalc(const unsigned int& _depositAmount = 1000, const unsigned int& _period = 1, const unsigned int& _rate = 1);
    void calc();
    void setDepositAmount(const unsigned int& depositAmount);
    void setPeriod(const unsigned int& period);
    void setRate(const unsigned int& rate);
    unsigned int getDepositAmount() const;
    unsigned int getPeriod() const;
    unsigned int getRate() const;
    unsigned int getDepositWithRate() const;
    unsigned int getInterestCharges() const;
};

#endif  // MODULES_DEPOSIT_CALCULATOR_INCLUDE_DEPOSITCALC_H_
