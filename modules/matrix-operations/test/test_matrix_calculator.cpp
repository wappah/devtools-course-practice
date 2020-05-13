// Copyright 2020 Golubev Vladislav

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "include/matrix_calculator.h"

using ::testing::internal::RE;

class MatrixCalculatorTest : public ::testing::Test {
 protected:
  void Act(std::vector<std::string> args_) {
    std::vector<const char*> options;

    options.push_back("MatrixCalculator");
    for (std::size_t i = 0; i < args_.size(); ++i) {
      options.push_back(args_[i].c_str());
    }

    const char** argv = &options.front();
    int argc = static_cast<int>(args_.size()) + 1;

    output_ = app_(argc, argv);
  }

  void Assert(std::string expected) {
    EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
  }

 private:
  MatrixCalculator app_;
  std::string output_;
};

TEST_F(MatrixCalculatorTest, DISABLED_Do_Print_Help_Without_Arguments) {
  std::vector<std::string> args = {};

  Act(args);

  Assert("This is a matrix calculator application.");
}

TEST_F(MatrixCalculatorTest, DISABLED_Is_Checking_Number_Of_Arguments) {
  std::vector<std::string> args = { "1.0", "2.0", "3.0", "*" };

  Act(args);

  Assert("Should be 9 or 6 or 5 arguments!");
}

TEST_F(MatrixCalculatorTest, DISABLED_Can_Detect_Wrong_Number_Format) {
  std::vector<std::string> args = { "1.0", "kryak", "3.0", "1.0", "T" };

  Act(args);

  Assert("Wrong number format!");
}

TEST_F(MatrixCalculatorTest, DISABLED_Can_Detect_Wrong_Operation_Format) {
  std::vector<std::string> args = { "1.0", "2.0", "3.0", "1.0",
    "2.0", "3.0", "2.0", "3.0", "+-" };

  Act(args);

  Assert("Wrong operation format!");
}

TEST_F(MatrixCalculatorTest, Can__Add_Matrixes) {
  std::vector<std::string> args = { "1.0", "2.0", "3.0", "4.0", "4.0", "3.0", "2.0", "1.0", "+" };

  Act(args);

  Assert("A + B = 5.0 5.0 5.0 5.0 ");
}
