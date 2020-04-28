// Copyright 2020 Golovanova Elena

#include "include/quick_sort.h"
#include <random>
#include <ctime>
#include <vector>

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

void QuickSort::QSort(std::vector<int> &_matrix, int _first, int _last) {
  int first, last, supporting;
  first = _first;
  last = _last;
  supporting = _matrix[(first + last) / 2];
  do {
    while (_matrix[first] < supporting) {
      first++;
    }
    while (_matrix[last] > supporting) {
      last--;
    }
    if (last <= first) {
      std::swap(_matrix[first], _matrix[last]);
      first++;
      last--;
    }
  } while (first <= last);
  if (_first < last)
    QSort(_matrix, _first, last);
  if (first < _last)
    QSort(_matrix, first, _last);
}

std::vector<int> QuickSort::main(QuickSort Elementary) {
  if (Elementary.matrix.empty())
    throw "Matrix is empty";
  for (int i = 0; i < Elementary.size - 1; i++)
    if (Elementary.matrix[i] < Elementary.matrix[i + 1])
      throw "Matrix is sorted";
  QSort(Elementary.matrix, 0, Elementary.size - 1);
  for (int i = 0; i < Elementary.size - 1; i++)
    if (Elementary.matrix[i] > Elementary.matrix[i + 1])
      throw "Matrix is not sorted";
  return Elementary.matrix;
}
