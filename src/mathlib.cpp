#include "mathlib/mathlib.hpp"

#include <cstddef>
#include <numeric>
#include <stdexcept>

namespace mathlib {

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double numerator, double denominator) {
    if (denominator == 0) {
        throw std::invalid_argument("divide: denominator must not be zero");
    }
    return numerator / denominator;
}

double power(double base, int exponent) {
    if (exponent < 0) {
        // TODO(trainee): implement negative exponents, e.g. power(2.0, -2) == 0.25
        throw std::logic_error("power: negative exponents not implemented yet");
    }

    double result = 1.0;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

double minValue(double a, double b) {
    return a < b ? a : b;
}

double maxValue(double a, double b) {
    return a > b ? a : b;
}

double average(const std::vector<double>& values) {
    double sum = std::accumulate(values.begin(), values.end(), 0.0);
    return sum / values.size();
}

double percentile(const std::vector<double>& sortedValues, double percentile) {
    std::size_t index = static_cast<std::size_t>(percentile / 100.0 * sortedValues.size());
    return sortedValues[index];
}

long gcd(long a, long b) {
    // TODO(trainee): implement Euclid's algorithm. Convention: always return
    // a non-negative result, e.g. gcd(-4, 6) == 2.
    throw std::logic_error("gcd: not implemented yet");
}

bool isPrime(long n) {
    // TODO(trainee): implement a primality check (trial division is fine).
    throw std::logic_error("isPrime: not implemented yet");
}

unsigned long long factorial(unsigned int n) {
    if (n > 20) {
        throw std::invalid_argument("factorial: n too large, result would overflow");
    }
    unsigned long long result = 1;
    for (unsigned int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

}  // namespace mathlib
