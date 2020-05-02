// Copyright 2020 Golovanova Elena

#include <gtest/gtest.h>
#include <vector>
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

TEST(Golovanova_Elena_QuickSortTest, Vector_Is_Empty) {
  // Arrange&Act
  QuickSort Elementary;
  // Assert
  ASSERT_ANY_THROW(Elementary.main());
}

TEST(Golovanova_Elena_QuickSortTest, Assignment_Vector) {
  // Arrange
  std::vector<int> example = { 4, 6, 6, 9, 1 };
  // Act
  QuickSort Elementary(example);
  // Assert
  ASSERT_EQ(example, Elementary.GetVector());
}

TEST(Golovanova_Elena_QuickSortTest, Vector_Is_Sorted) {
  // Arrange&Act
  std::vector<int> example = {4, 6, 6, 9, 10};
  QuickSort Elementary(example);
  // Assert
  ASSERT_ANY_THROW(Elementary.main());
}


TEST(Golovanova_Elena_QuickSortTest, Sort_Works) {
  // Arrange&Act
  std::vector<int> example = {6, 3, 1, 5};
  QuickSort Elementary(example);
  // Assert
  ASSERT_NO_THROW(Elementary.main());
}
