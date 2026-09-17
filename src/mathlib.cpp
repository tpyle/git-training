#include "mathlib/mathlib.hpp"

#include <cstddef>
#include <cstdlib>
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
        return 1.0 / power(base, -exponent);
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

double average(const double* values, std::size_t count) {
    double sum = 0.0;
    for (std::size_t i = 0; i < count; ++i) {
        sum += values[i];
    }
    return sum / count;
}

double percentile(const double* sortedValues, std::size_t count, double percentile) {
    std::size_t index = static_cast<std::size_t>(percentile / 100.0 * count);
    return sortedValues[index];
}

long gcd(long a, long b) {
    a = std::abs(a);
    b = std::abs(b);
    while (b != 0) {
        long remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

long lcm(long a, long b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    return std::abs(a * b) / gcd(a, b);
}

bool isPrime(long n) {
    if (n < 2) {
        return false;
    }
    for (long divisor = 2; divisor * divisor <= n; ++divisor) {
        if (n % divisor == 0) {
            return false;
        }
    }
    return true;
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

unsigned long long fibonacci(unsigned int n) {
    unsigned long long previous = 0;
    unsigned long long current = 1;
    for (unsigned int i = 0; i < n; ++i) {
        unsigned long long next = previous + current;
        previous = current;
        current = next;
    }
    return previous;
}

bool isPerfectSquare(long n) {
    if (n < 0) {
        return false;
    }
    long guess = 0;
    while (guess * guess < n) {
        ++guess;
    }
    return guess * guess == n;
}

}  // namespace mathlib
