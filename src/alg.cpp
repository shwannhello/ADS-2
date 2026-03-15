// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
double pown(double value, uint16_t n) {
    double result = 1.0;
    for (uint16_t i = 0; i < n; ++i) {
        result = result * value;
    }
    return result;
}
uint64_t fact(uint16_t n) {
    uint64_t result = 1;
    for (uint16_t i = 2; i <= n; ++i) {
        result = result * i;
    }
    return result;
}
double calcItem(double x, uint16_t n) {
    double power = pown(x, n);
    uint64_t factorial = fact(n);
    if (factorial == 0) {
        return 0.0;
    }
    return power / factorial;
}
double expn(double x, uint16_t count) {
    double result = 1.0;
    double term = 1.0;
    for (uint16_t n = 1; n < count; ++n) {
        term = term * x / n;
        result = result + term;
    }
    return result;
}
double sinn(double x, uint16_t count) {
    double result = x;
    double term = x;
    for (uint16_t n = 1; n < count; ++n) {
        term = term * (-1.0) * x * x;
        term = term / ((2 * n) * (2 * n + 1));
        result = result + term;
    }
    return result;
}
double cosn(double x, uint16_t count) {
    double result = 1.0;
    double term = 1.0;
    for (uint16_t n = 1; n < count; ++n) {
        term = term * (-1.0) * x * x;
        term = term / ((2 * n - 1) * (2 * n));
        result = result + term;
    }
    return result;
}
