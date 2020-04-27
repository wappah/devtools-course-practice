//Copyright 2020 Golovanova Elena

#include "include/quick_sort.h"

QuickSort::QuickSort(){
  size = 0;
}

QuickSort::QuickSort(int _size) {
  if (_size < 0)
    throw "Size is negative";
  size = _size;
}