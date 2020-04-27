// Copyright 2020 Golovanova Elena

#include "include/quick_sort.h"
#include <random>
#include <ctime>

QuickSort::QuickSort() {
  size = 0;
}

QuickSort::QuickSort(int _size) {
  if (_size < 0)
    throw "Size is negative";
  size = _size;
}

int QuickSort::GetSize() {
  return size;
}

std::vector<int> QuickSort::GetRandom(QuickSort Elementary) {
  std::mt19937 gen;
  gen.seed(static_cast<unsigned int>(time(0)));
  Elementary.matrix.resize(Elementary.size, 0);
  for (int i = 0; i < Elementary.size; i++)
    Elementary.matrix[i] = gen();
  return Elementary.matrix;
}

std::vector<int> QuickSort::Sort(QuickSort Elementary) {
  for (int i = 0; i < Elementary.size - 1; i++)
    if (Elementary.matrix[i] < Elementary.matrix[i + 1])
      throw "Matrix is sorted";

  return Elementary.matrix;
}

// std::vector<int> QuickSort::Sort(QuickSort Elementary) {
//  for (int i = 0; i < Elementary.size - 1; i++)
//    if (Elementary.matrix[i] < Elementary.matrix[i + 1])
//      throw "Matrix is sorted";
//
//  return Elementary.matrix;
//}
