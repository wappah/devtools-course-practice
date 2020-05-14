// Copyright 2020 Golovanova Elena

#include "include/quick_sort.h"

#include <vector>

QuickSort::QuickSort(std::vector<int> _vector) : vector(_vector) {}

std::vector<int> QuickSort::GetVector()const {
  return vector;
}

int QuickSort::GetIndex(int _first, int _last) {
  int supporting;
  supporting = vector[(_first+_last)/2];
  while (_first < _last) {
    while (vector[_first] < supporting) {
      _first++;
    }
    while (vector[_last] > supporting) {
      _last--;
    }
    if (_first < _last)
      std::swap(vector[_first], vector[_last]);
  }
  return _first;
}

void QuickSort::QSort(int _first, int _last) {
  if (_first < _last) {
    int middle = GetIndex(_first, _last);
    QSort(_first, middle);
    QSort(middle + 1, _last);
  }
}

std::vector<int> QuickSort::main() {
  if (vector.empty())
    throw "Matrix is empty";
  bool flag = true;
  for (unsigned int i = 0; i < vector.size() - 1; i++)
    if (vector[i] > vector[i + 1]) {
      flag = false;
      break;
    }
  if (flag == true)
    throw "Vector is sorted";
  QSort(0, vector.size() - 1);
  return GetVector();
}
