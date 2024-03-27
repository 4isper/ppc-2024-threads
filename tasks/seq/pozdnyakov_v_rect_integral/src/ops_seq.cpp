// Copyright 2024 Pozdnyakov Vasya
#include "seq/pozdnyakov_v_rect_integral/include/ops_seq.hpp"

double flin(double x, double y) { return x - y; }
double fxy(double x, double y) { return x * y; }
double fysinx(double x, double y) { return y * std::sin(x); }
double fxexpy(double x, double y) { return x * std::exp(y); }

bool PozdnyakovTaskSequential::pre_processing() {
  internal_order_test();
  try {
    double* tmp = reinterpret_cast<double*>(taskData->inputs[0]);
    x1 = tmp[0], x2 = tmp[1], y1 = tmp[2], y2 = tmp[3];
    n = 5000;
    res = 0.0;
    f = reinterpret_cast<Func>(taskData->inputs[1]);
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
    return false;
  }
  return true;
}

bool PozdnyakovTaskSequential::validation() {
  internal_order_test();
  return taskData->inputs_count[0] == 4 && taskData->outputs_count[0] == 1;
}

bool PozdnyakovTaskSequential::run() {
  internal_order_test();
  try {
    double x_i = std::abs(x2 - x1) / n, y_i = std::abs(y2 - y1) / n;
    for (uint64_t i = 0; i < n; i++) {
      for (uint64_t j = 0; j < n; j++) {
        res += f(x1 + i * x_i, y1 + j * y_i);
      }
    }
    res *= x_i * y_i;
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
    return false;
  }
  return true;
}

bool PozdnyakovTaskSequential::post_processing() {
  internal_order_test();
  try {
    reinterpret_cast<double*>(taskData->outputs[0])[0] = res;
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
    return false;
  }
  return true;
}
