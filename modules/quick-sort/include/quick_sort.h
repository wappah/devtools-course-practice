// Copyright 2020 Golovanova Elena

#ifndef MODULES_QUICK_SORT_INCLUDE_QUICK_SORT_H_
#define MODULES_QUICK_SORT_INCLUDE_QUICK_SORT_H_

#include <iostream>
#include <vector>

class QuickSort {
 public:
  int size;
  std::vector<int> matrix;
  QuickSort();
  explicit QuickSort(int _size);
  QuickSort(int _size, int element);
  int GetSize();
  std::vector<int>Sort(QuickSort Elementary);
};

#endif  // MODULES_QUICK_SORT_INCLUDE_QUICK_SORT_H_
