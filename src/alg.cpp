// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    if (n == 0) {
        return 1.0;
    }
    double result = 1.0;
    for (uint16_t i = 0; i < n; ++i) {
        result *= value;
    }
    return result;
}

uint64_t fact(uint16_t n) {
    if (n == 0 || n == 1) {
        return 1ULL;
    }
    uint64_t result = 1ULL;
    for (uint16_t i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

double calcItem(double x, uint16_t n) {
    if (n == 0) {
        return 1.0;
    }
    double power = pown(x, n);
    uint64_t factorial = fact(n);
    return power / static_cast<double>(factorial);
}

double expn(double x, uint16_t count) {
    if (count == 0) {
        return 0.0;
    }
    double result = 0.0;
    double term = 1.0;  // первый член ряда (n=0)
    
    for (uint16_t n = 0; n < count; ++n) {
        if (n == 0) {
            result += term;
        } else {
            term *= x / static_cast<double>(n);
            result += term;
        }
    }
    return result;
}

double sinn(double x, uint16_t count) {
    if (count == 0) {
        return 0.0;
    }
    double result = 0.0;
    double term = x;  // первый член ряда (n=0)
    int sign = 1;
    
    for (uint16_t n = 0; n < count; ++n) {
        if (n == 0) {
            result += term;
        } else {
            term *= -x * x / static_cast<double>((2*n) * (2*n + 1));
            result += term;
        }
    }
    return result;
}

double cosn(double x, uint16_t count) {
    if (count == 0) {
        return 0.0;
    }
    double result = 0.0;
    double term = 1.0;  // первый член ряда (n=0)
    int sign = 1;
    
    for (uint16_t n = 0; n < count; ++n) {
        if (n == 0) {
            result += term;
        } else {
            term *= -x * x / static_cast<double>((2*n - 1) * (2*n));
            result += term;
        }
    }
    return result;
}
