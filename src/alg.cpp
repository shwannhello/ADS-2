// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    if (n == 0) {
        return 1.0;
    }
    double result = 1.0;
    for (uint16_t i = 0; i < n; ++i) {
        result = result * value;
    }
    return result;
}

uint64_t fact(uint16_t n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    uint64_t result = 1;
    for (uint16_t i = 2; i <= n; ++i) {
        result = result * i;
    }
    return result;
}

double calcItem(double x, uint16_t n) {
    double power = pown(x, n);
    uint64_t factorial = fact(n);
    return power / factorial;
}

double expn(double x, uint16_t count) {
    if (count == 0) {
        return 0.0;
    }
    double result = 0.0;
    double term = 1.0;
    for (uint16_t n = 0; n < count; ++n) {
        if (n > 0) {
            term = term * x / n;
        }
        result = result + term;
    }
    return result;
}

double sinn(double x, uint16_t count) {
    if (count == 0) {
        return 0.0;
    }
    double result = 0.0;
    double term = x;
    for (uint16_t n = 0; n < count; ++n) {
        if (n == 0) {
            result = result + term;
        } else {
            term = term * (-1.0) * x * x / ((2 * n) * (2 * n + 1));
            result = result + term;
        }
    }
    return result;
}

double cosn(double x, uint16_t count) {
    if (count == 0) {
        return 0.0;
    }
    double result = 0.0;
    double term = 1.0;
    for (uint16_t n = 0; n < count; ++n) {
        if (n == 0) {
            result = result + term;
        } else {
            term = term * (-1.0) * x * x / ((2 * n - 1) * (2 * n));
            result = result + term;
        }
    }
    return result;
}
