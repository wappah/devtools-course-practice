// Copyright 2020 Golovanova Elena

#include "include/quick_sort.h"
#include <random>
#include <ctime>
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
  for (int i = 0; i < _vector.size(); i++)
    matrix[i] = _vector[i];
}

std::vector<int> QuickSort::GetVector() {
  return matrix;
}

int QuickSort::GetIndex(const std::vector<int>& _matrix, int _first, int _last) {
  QuickSort Result(_matrix);
  int first, last, supporting;
  supporting = Result.matrix[_first];
  first = _first;
  last = _last;
  while (true) {
    while (Result.matrix[first] < supporting) {
      first++;
    }
    while (Result.matrix[last] > supporting){
      last--;
    }
    if (first >= last)
      return last;
    std::swap(Result.matrix[first], Result.matrix[last]);
  }
}

std::vector<int> QuickSort::QSort(const std::vector<int>& _matrix, int _first, int _last) {
  int middle;
  QuickSort Result(_matrix);
  if (_first < _last) {
    middle = GetIndex(Result.matrix, _first, _last);
    QSort(Result.matrix, _first, middle);
    QSort(Result.matrix, middle+1, _last);
  }
  return Result.matrix;
  /*for (int i = 0; i < _last; i++)
    std::cout << Result.matrix[i];*/
    /*if (Elementary.matrix[i] <= Elementary.matrix[i + 1])
    throw "Vector is sorted";*/
}

//std::vector<int> QuickSort::QSort(const std::vector<int>& _matrix, int _first, int _last) {
//  QuickSort Result(_matrix);
//  int first, last, supporting;
//  if (_first <_last) {
//    first = _first;
//    last = _last;
//    supporting = Result.matrix[(first + last) / 2];
//    do {
//      while (Result.matrix[first] < supporting) {
//        first++;
//      }
//      while (Result.matrix[last] > supporting) {
//        last--;
//      }
//      if (first <= last) {
//        std::swap(Result.matrix[first++], Result.matrix[last--]);
//        first++;
//        last--;
//      }
//    } while (first < last);
//    if (_first < last)
//      QSort(Result.matrix, _first, last);
//    if (first < _last)
//      QSort(Result.matrix, first, _last);
//  }

  /*for (int i = 0; i < Result.matrix.size() ; i++) 
    std::cout << Result.matrix[i];
  
  for (int i = 0; i < Result.matrix.size() - 1; i++) {
    if (Result.matrix[i] > Result.matrix[i + 1])
      throw "Matrix is not sorted";
  }
  return Result.matrix;
}*/

std::vector<int> QuickSort::main(QuickSort Elementary) {
  if (Elementary.matrix.empty())
    throw "Matrix is empty";
  int flag = 0;
  int end_index = Elementary.matrix.size() - 1;
  for (int i = 0; i < end_index; i++)
    if (Elementary.matrix[i] <= Elementary.matrix[i + 1])
      flag++;
  if (flag == end_index)
    throw "Vector is sorted";
  std::vector<int> Result = QSort(Elementary.matrix, 0, end_index);
  Elementary.matrix.clear();
  for (int i = 0; i < Result.size(); i++)
    if (Result[i] > Result[i + 1])
      throw "Vector is sorted";
  return Result;
  //Elementary.matrix.clear();
}
