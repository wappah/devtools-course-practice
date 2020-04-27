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

QuickSort::QuickSort(int _size, int element) {
  if (_size < 0)
    throw "Size is negative";
  size = _size;
  matrix.resize(size, element);
}

std::vector<int> QuickSort::Sort(QuickSort Elementary) {
  if (Elementary.matrix.empty())
    throw "Matrix is empty";
  for (int i = 0; i < Elementary.size - 1; i++)
    if (Elementary.matrix[i] < Elementary.matrix[i + 1])
      throw "Matrix is sorted";
  return Elementary.matrix;
}

