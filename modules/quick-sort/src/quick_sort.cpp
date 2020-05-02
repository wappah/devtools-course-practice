// Copyright 2020 Golovanova Elena

#include "include/quick_sort.h"
#include <random>
#include <algorithm>
#include <vector>

QuickSort::QuickSort() {}

QuickSort::QuickSort(int _size) {
  if (_size < 0)
    throw "Size is negative";
  matrix.resize(_size, 0);
}

QuickSort::QuickSort(std::vector<int>_vector) {
  if (_vector.size() < 0)
       throw "Size is negative";
  matrix.resize(_vector.size(), 0);
  for (unsigned int i = 0; i < _vector.size(); i++)
    matrix[i] = _vector[i];
}

std::vector<int> QuickSort::GetVector() {
  return matrix;
}

int QuickSort::GetIndex(int _first, int _last) {
  int first, last, supporting;
  supporting = matrix[(_first+_last)/2];
  first = _first;
  last = _last;
  while (first < last) {
    while (matrix[first] < supporting) {
      first++;
    }
    while (matrix[last] > supporting) {
      last--;
    }
    if (first < last)
      std::swap(matrix[first], matrix[last]);
  }
  return first;
}

void QuickSort::QSort(int _first, int _last) {
  if (_first < _last) {
    int middle = GetIndex(_first, _last);
    QSort(_first, middle);
    QSort(middle + 1, _last);
  }
}

void QuickSort::main() {
  if (matrix.empty())
    throw "Matrix is empty";
  bool flag = true;
  // int end_index = Elementary.matrix.size() - 1;
  for (unsigned int i = 0; i < matrix.size() - 1; i++)
    if (matrix[i] > matrix[i + 1]) {
      flag = false;
      break;
    }
  if (flag == true)
    throw "Vector is sorted";
  QSort(0, matrix.size() - 1);
  // for (unsigned long int i = 0; i < matrix.size(); i++)
  // std::cout << matrix[i];
  for (unsigned int i = 0; i < matrix.size()-1; i++)
    if (matrix[i] > matrix[i + 1])
      throw "Vector is not sorted";
}
