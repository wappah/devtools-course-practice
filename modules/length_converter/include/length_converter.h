// Copyright 2020 Sokova Anastasia
#ifndef MODULES_LENGTH_CONVERTER_INCLUDE_LENGTH_CONVERTER_H_
#define MODULES_LENGTH_CONVERTER_INCLUDE_LENGTH_CONVERTER_H_

class LengthConverter {
 private:
    double curr;
    bool side;
 public:
    LengthConverter() : curr(0), side(false) {}
    LengthConverter(double currency, bool amount)
        : curr(currency), side(amount) {}
    double m_kmeter(const double& curr, bool side);
    double m_smeter(const double& curr, bool side);
    double m_mile(const double& curr, bool side);
    double m_yard(const double& curr, bool side);
    double m_ft(const double& curr, bool side);
    double m_inch(const double& curr, bool side);
};

#endif  // MODULES_LENGTH_CONVERTER_INCLUDE_LENGTH_CONVERTER_H_
