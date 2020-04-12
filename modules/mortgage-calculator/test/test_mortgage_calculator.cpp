// Copyright 2020 Petrov Anton

#include "include/MortgageCalc.h"
#include <gtest/gtest.h>
TEST(CalculatorTest, Can_Set_Cost) {
    // Arrange
    int num = 1000000;
    // Act
    MortgageCalc mortgage(0, 0, 0, 0);
    mortgage.setCost(num);
    // Assert
    EXPECT_EQ(mortgage.getCost(), num);
}

TEST(CalculatorTest, Can_Set_DownPayment) {
    // Arrange
    int num = 1000000;
    // Act
    MortgageCalc mortgage(0, 0, 0, 0);
    mortgage.setDownPayment(num);
    // Assert
    EXPECT_EQ(mortgage.getDownPayment(), num);
}

TEST(CalculatorTest, Can_Set_CreditTerm) {
    // Arrange
    int num = 1000000;
    // Act
    MortgageCalc mortgage(0, 0, 0, 0);
    mortgage.setCreditTerm(num);
    // Assert
    EXPECT_EQ(mortgage.getCreditTerm(), num);
}

TEST(CalculatorTest, Can_Set_InterestRate) {
    // Arrange
    int num = 10;
    // Act
    MortgageCalc mortgage(0, 0, 0, 0);
    mortgage.setInterestRate(num);
    // Assert
    EXPECT_EQ(mortgage.getInterestRate(), num);
}

TEST(CalculatorTest, Can_Get_TotalFee) {
    // Arrange
    int num = 3872038;
    // Act
    MortgageCalc mortgage(2000000, 0, 10, 15);
    mortgage.calc();
    // Assert
    EXPECT_EQ(mortgage.getTotalFee(), num);
}

TEST(CalculatorTest, Can_Get_MonthlyPayment) {
    // Arrange
    int num = 32266;
    // Act
    MortgageCalc mortgage(2000000, 0, 10, 15);
    mortgage.calc();
    // Assert
    EXPECT_EQ(mortgage.getMonthlyPayment(), num);
}

TEST(CalculatorTest, Can_Get_MonthlyRate) {
    // Arrange
    double num = 0.0125;
    // Act
    MortgageCalc mortgage(2000000, 0, 10, 15);
    mortgage.calc();
    // Assert
    EXPECT_DOUBLE_EQ(mortgage.getMonthlyRate(), num);
}

TEST(CalculatorTest, Can_Calculation_With_Zero_Numbers) {
    // Arrange
    // Act
    MortgageCalc mortgage(0, 0, 0, 0);
    // Assert
    ASSERT_TRUE(mortgage.getTotalFee());
}

TEST(CalculatorTest, Is_Copy_Constructort_Working_Fine) {
    // Arrange
    // Act
    MortgageCalc mortgage(1, 1, 1, 1);
    MortgageCalc mortgage2(mortgage);
    // Assert
    EXPECT_EQ(mortgage2.getCost(), mortgage.getCost());
    EXPECT_EQ(mortgage2.getDownPayment(), mortgage.getDownPayment());
    EXPECT_EQ(mortgage2.getCreditTerm(), mortgage.getCreditTerm());
    EXPECT_DOUBLE_EQ(mortgage2.getInterestRate(), mortgage.getInterestRate());
}

TEST(CalculatorTest, Create_Copy_Constructor) {
    // Arrange
    // Act
    MortgageCalc mortgage(1, 1, 1, 1);
    MortgageCalc mortgage2(mortgage);
    // Assert
    ASSERT_NO_THROW(mortgage2.getCost());
    ASSERT_NO_THROW(mortgage2.getDownPayment());
    ASSERT_NO_THROW(mortgage2.getCreditTerm());
    ASSERT_NO_THROW(mortgage2.getInterestRate());
}
