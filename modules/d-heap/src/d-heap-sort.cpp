// Copyright 2020 Guschin Alexandr

#include "include/d-heap-sort.h"
#include <algorithm>

d_heap_sort::d_heap_sort() { ret_str = ""; }

bool d_heap_sort::validateNumberOfArguments(int argc, const char** argv) {
  if (argc < 2) {
    ret_str = Help();
    return false;
  }
  return true;
}

int d_heap_sort::ParseOp(const char** Op) {
  if (std::strcmp(Op[0], "add") == 0) {
    int value = ParseArg(Op + 1);
    heap.insert(value);
    return 1;
  }
  if (std::strcmp(Op[0], "del") == 0) {
    int value = ParseArg(Op + 1);
    heap.del(heap.getInd(value));
    return 1;
  }
  if (std::strcmp(Op[0], "sort") == 0) {
    d_heap copy(heap);
    while (copy.getCount() != 0) {
      ret_str += std::to_string(copy[0]) += " ";
      copy.del(0);
    }
    ret_str += "\n";
    return 0;
  }

  if (std::strcmp(Op[0], "show") == 0) {
    for (int i = 0; i < heap.getCount(); ++i)
      ret_str += std::to_string(heap[i]) += " ";
    ret_str += "\n";
    return 0;
  }

  throw std::invalid_argument("Bad arguments!");
}

int d_heap_sort::ParseArg(const char** Arg) { return std::atoi(Arg[0]); }

std::string d_heap_sort::operator()(int argc, const char** argv) {
  if (validateNumberOfArguments(argc, argv) == 0) return ret_str;

  for (int i = 1; i < argc; ++i) {
    int shift = ParseOp(argv + i);
    i += shift;
  }

  return ret_str;
}

std::string d_heap_sort::Help() { return "TEST\n"; }
