// Copyright 2020 Golovanova Elena

#include <gtest/gtest.h>
#include "include/quick_sort.h"

TEST(Golovanova_Elena_QuickSortTest, Create_Empty_Class) {
  // Arrange&Act&Assert
  ASSERT_NO_THROW(QuickSort ex1);
}

TEST(Golovanova_Elena_QuickSortTest, Create_Class_With_Negative_Parameters) {
  // Arrange&Act&Assert
  ASSERT_ANY_THROW(QuickSort ex1(-1));
}

TEST(Golovanova_Elena_QuickSortTest, Create_Class_With_Positive_Parameters) {
  // Arrange&Act&Assert
  ASSERT_NO_THROW(QuickSort ex1(5));
}

TEST(Golovanova_Elena_QuickSortTest, Return_Size) {
  //Arrange&Act
  QuickSort ex1(5);
  //Assert
  ASSERT_EQ(5, ex1.GetSize());
}

TEST(Golovanova_Elena_QuickSortTest, Vector_Is_Empty) {
  //Arrange&Act
  QuickSort ex1(5);
  //Assert
  ASSERT_TRUE(ex1.matrix.empty());
}

TEST(Golovanova_Elena_QuickSortTest, Vector_Is_Not_Empty) {
  //Arrange&Act
  QuickSort Elementary(10);
  Elementary.matrix= Elementary.GetRandom(Elementary);
  //Assert
  ASSERT_FALSE(Elementary.matrix.empty());
}

