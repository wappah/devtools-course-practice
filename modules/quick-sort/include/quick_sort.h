//Copyright 2020 Golovanova Elena

#ifndef MODULES_QUICK_SORT_INCLUDE_QUICK_SORT_H_
#define MODULES_QUICK_SORT_INCLUDE_QUICK_SORT_H_

#include <iostream>
#include <vector>

class QuickSort {
 private:
   int size;
   std::vector<int> matrix;
 public:
   QuickSort();
   QuickSort(int _size);
   int GetSize();
};

#endif  // MODULES_QUICK_SORT_INCLUDE_QUICK_SORT_H_