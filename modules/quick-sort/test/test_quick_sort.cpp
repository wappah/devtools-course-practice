// Copyright 2020 Golovanova Elena

#include <gtest/gtest.h>
#include "include/quick_sort.h"

TEST(Golovanova_Elena_QuickSortTest, Create_Empty_Class) {
  // Arrange&Act&Assert
  ASSERT_NO_THROW(QuickSort Elementary);
}

TEST(Golovanova_Elena_QuickSortTest, Create_Class_With_Negative_Parameters) {
  // Arrange&Act&Assert
  ASSERT_ANY_THROW(QuickSort Elementary(-1));
}

TEST(Golovanova_Elena_QuickSortTest, Create_Class_With_Positive_Parameters) {
  // Arrange&Act&Assert
  ASSERT_NO_THROW(QuickSort Elementary(5));
}

TEST(Golovanova_Elena_QuickSortTest, Return_Size) {
  // Arrange&Act
  QuickSort Elementary(5);
  // Assert
  ASSERT_EQ(5, Elementary.GetSize());
}

TEST(Golovanova_Elena_QuickSortTest, Vector_Is_Empty) {
  // Arrange&Act
  QuickSort Elementary(5);
  // Assert
  ASSERT_ANY_THROW(Elementary.main(Elementary));
}

TEST(Golovanova_Elena_QuickSortTest, Vector_Is_Sorted) {
  // Arrange
  QuickSort Elementary(5, 0);
  // Act
  Elementary.matrix = { 4, 6, 6, 9, 1};
  // Assert
  ASSERT_ANY_THROW(Elementary.main(Elementary));
}

TEST(Golovanova_Elena_QuickSortTest, Sort_Works) {
  // Arrange
  QuickSort Elementary(6, 0);
  // Act
  Elementary.matrix = { 4, 10, 11, 9, 1, 1 };
  // Assert
  ASSERT_ANY_THROW(Elementary.main(Elementary));
}

