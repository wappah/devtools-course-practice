// Copyright 2020 Antipin Alexander

#ifndef MODULES_D_HEAP_SORT_INCLUDE_D_HEAP_H_
#define MODULES_D_HEAP_SORT_INCLUDE_D_HEAP_H_

#include <stdint.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include "include/d-heap.h"

class d_heap_sort {
 private:
  d_heap heap;

 public:
  d_heap_sort();
  std::string operator()(int argc, const char** argv);
 
};

#endif  // MODULES_D_HEAP_SORT_INCLUDE_D_HEAP_H_
