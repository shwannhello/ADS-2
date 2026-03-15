// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

double pown(double value, uint16_t n) {
    double result = 1.0;
    for (uint16_t i = 0; i < n; ++i) {
        result *= value;
    }
    return result;
}

uint64_t fact(double value, uint16_t n) {
    uint64_t result = 1;
    for (uint16_t i = 0; i <= n; ++i) {
        result *= value;
    }
    return result;
}

double calcItem(double x, uint16_t n) {
    double power = pown(x, n);
    uint64_t factorial = fact(n);
    if (factorial == 0) {
        return 0.0;
    }
    return power / static_cast<double>(factorial);
}

double expn(double x, uint16_t count) {
  double sum = 0.0;
  for (uint16_t n = 0; n <= count; n++) {
    sum += calcItem(x, n);
  }
  return sum;
}

double sinn(double x, uint16_t count) {
  double sum = 0.0;
  for (uint16_t n = 0; n < count; n++) {
    // Члены ряда sin(x): (-1)^n * x^(2n+1) / (2n+1)!
    double term = pown(-1.0, n) * pown(x, 2 * n + 1) / fact(2 * n + 1);
    sum += term;
  }
  return sum;
}

double cosn(double x, uint16_t count) {
  double sum = 0.0;
  for (uint16_t n = 0; n < count; n++) {
    // Члены ряда cos(x): (-1)^n * x^(2n) / (2n)!
    double term = pown(-1.0, n) * pown(x, 2 * n) / fact(2 * n);
    sum += term;
  }
  return sum;
}
