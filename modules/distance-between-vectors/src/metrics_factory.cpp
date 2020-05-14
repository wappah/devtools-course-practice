// Copyright 2020 Sokolov Andrey

#ifndef MODULES_DISTANCE_BETWEEN_VECTORS_INCLUDE_METRICS_FACTORY_CPP_
#define MODULES_DISTANCE_BETWEEN_VECTORS_INCLUDE_METRICS_FACTORY_CPP_

#include <string>
#include <vector>

#include "include/distance_between_vectors.h"
#include "include/metrics_factory.h"

Metrics* metricsFactory::create(const std::string& _operation) {
  if (_operation == "L1") {
    return new MetricsL1;
  } else if (_operation == "L2") {
    return new MetricsL2;
  } else if (_operation == "L3") {
    return new MetricsL3;
  } else if (_operation == "L4") {
    return new MetricsL4;
  } else if (_operation == "LInf") {
    return new MetricsLInf;
  } else {
    throw "Wrong operation name!";
    return nullptr;
  }
}

Metrics* metricsFactory::create(const std::string& _operation,
                                const std::vector<float>& _fst,
                                const std::vector<float>& _sec) {
  if (_operation == "L1") {
    return new MetricsL1(_fst, _sec);
  } else if (_operation == "L2") {
    return new MetricsL2(_fst, _sec);
  } else if (_operation == "L3") {
    return new MetricsL3(_fst, _sec);
  } else if (_operation == "L4") {
    return new MetricsL4(_fst, _sec);
  } else if (_operation == "LInf") {
    return new MetricsLInf(_fst, _sec);
  } else {
    throw "Wrong operation name!";
    return nullptr;
  }
}

#endif  // MODULES_DISTANCE_BETWEEN_VECTORS_INCLUDE_METRICS_FACTORY_CPP_
