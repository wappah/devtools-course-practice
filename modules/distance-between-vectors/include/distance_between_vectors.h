// Copyright 2020 Vladislav Golubev

#ifndef MODULES_DISTANCE_BETWEEN_VECTORS_INCLUDE_DISTANCE_BETWEEN_VECTORS_H_
#define MODULES_DISTANCE_BETWEEN_VECTORS_INCLUDE_DISTANCE_BETWEEN_VECTORS_H_
#include <vector>

class Metrics {
 protected:
  std::vector<float> fst;
  std::vector<float> sec;

 public:
  Metrics();
  Metrics(const Metrics&) = default;
  Metrics(const std::vector<float>& _fst, const std::vector<float>& _sec);
  virtual ~Metrics() = default;

  std::vector<float> getFirst() const;
  std::vector<float> getSecond() const;

  void setFirst(const std::vector<float>& _fst);
  void setSecond(const std::vector<float>& _sec);
  void setBoth(const std::vector<float>& _fst, const std::vector<float>& _sec);

  virtual double getMetrics() const;
};

class MetricsL1 : public Metrics {
 public:
  MetricsL1() : Metrics() {};
  MetricsL1(const Metrics&) : Metrics() {};
  MetricsL1(const std::vector<float>& _fst, const std::vector<float>& _sec) : Metrics(_fst, _sec) {};
  ~MetricsL1() = default;

  double getMetrics() const override final;
};

class MetricsL2 : public Metrics {
public:
  MetricsL2() : Metrics() {};
  MetricsL2(const Metrics&) : Metrics() {};
  MetricsL2(const std::vector<float>& _fst, const std::vector<float>& _sec) : Metrics(_fst, _sec) {};
  ~MetricsL2() = default;
  double getMetrics() const override final;
};

class MetricsL3 : public Metrics {
public:
  MetricsL3() : Metrics() {};
  MetricsL3(const Metrics&) : Metrics() {};
  MetricsL3(const std::vector<float>& _fst, const std::vector<float>& _sec) : Metrics(_fst, _sec) {};
  ~MetricsL3() = default;
  double getMetrics() const override final;
};

class MetricsL4 : public Metrics {
public:
  MetricsL4() : Metrics() {};
  MetricsL4(const Metrics&) : Metrics() {};
  MetricsL4(const std::vector<float>& _fst, const std::vector<float>& _sec) : Metrics(_fst, _sec) {};
  ~MetricsL4() = default;
  double getMetrics() const override final;
};

class MetricsLInf : public Metrics {
public:
  MetricsLInf() : Metrics() {};
  MetricsLInf(const Metrics&) : Metrics() {};
  MetricsLInf(const std::vector<float>& _fst, const std::vector<float>& _sec) : Metrics(_fst, _sec) {};
  ~MetricsLInf() = default;
  double getMetrics() const override final;
};

#endif  // MODULES_DISTANCE_BETWEEN_VECTORS_INCLUDE_DISTANCE_BETWEEN_VECTORS_H_
