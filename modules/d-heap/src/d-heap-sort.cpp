// Copyright 2020 Guschin Alexandr

#include "include/d-heap-sort.h"
#include <algorithm>
#include <cstring>
#include <string>

d_heap_sort::d_heap_sort():ret_str("") {}

bool d_heap_sort::validateNumberOfArguments(int argc, const char** argv) {
  if (argc == 1) {
    ret_str = Help(argv);
    return false;
  }
  return true;
}

int d_heap_sort::ParseOp(const char** Op) {
  if (strcmp(Op[0], "add") == 0) {
    int value = ParseArg(Op + 1);
    heap.insert(value);
    return 1;
  }
  if (strcmp(Op[0], "del") == 0) {
    int value = ParseArg(Op + 1);
    heap.del(heap.getInd(value));
    return 1;
  }
  if (strcmp(Op[0], "sort") == 0) {
    d_heap copy(heap);
    while (copy.getCount() != 0) {
      ret_str += std::to_string(copy[0]) + " ";
      copy.del(0);
    }
    ret_str += "\n";
    return 0;
  }

  if (strcmp(Op[0], "show") == 0) {
    int size = heap.getCount();
    for (int i = 0; i < size; ++i)
      ret_str += std::to_string(heap[i]) + " ";
    ret_str += "\n";
    return 0;
  }

  throw std::string("Bad arguments!");
}

int d_heap_sort::ParseArg(const char** Arg) {
  int res = std::atoi(Arg[0]);
  if (res < 0) throw std::string ("Negative number!");
  if (res == 0) throw std::string("Invalid Argument");
  return res;
}

std::string d_heap_sort::operator()(int argc, const char** argv) {
  if (validateNumberOfArguments(argc, argv) == 0) return ret_str;

  try {
    int i = 1;
    while (i < argc) {
      int shift = ParseOp(argv + i);
      i += shift;
      ++i;
    }
  } catch (std::string& str) {
    return str;
  }
  return ret_str;
}

std::string d_heap_sort::Help(const char** AppName) {
  return std::string ("This is D-Heap sorting application\n") +
         "Please provide arguments in following order\n" + "$ + " + AppName[0] +
         " <Arguments>\n" + "Where Arguments: \n" +
         "add <positive int> - add new element in heap\n" +
         "del <positive int> - delete element using value\n" +
         "show - showing elements in heap\n" +
         "sort - sorting and showing elements in heap\n";
}
