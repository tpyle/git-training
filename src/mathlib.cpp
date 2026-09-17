#include "mathlib/mathlib.hpp"

#include <cstddef>
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
    // TODO(trainee): implement Euclid's algorithm. Convention: always return
    // a non-negative result, e.g. gcd(-4, 6) == 2.
    //
    // Pseudocode (Euclid's algorithm):
    //   a = abs(a)
    //   b = abs(b)
    //   while b != 0:
    //       remainder = a mod b
    //       a = b
    //       b = remainder
    //   return a
    throw std::logic_error("gcd: not implemented yet");
}

long lcm(long a, long b) {
    // TODO(trainee): implement using lcm(a, b) = abs(a * b) / gcd(a, b),
    // once mathlib::gcd is implemented above. Watch out for a == 0 or
    // b == 0 - the formula still gives the right answer (lcm(0, n) == 0),
    // just make sure you're not dividing by a gcd of 0 to get there.
    throw std::logic_error("lcm: not implemented yet");
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

unsigned long long fibonacci(unsigned int n) {
    // TODO(trainee): implement this iteratively - don't recurse the
    // textbook way (fibonacci(n-1) + fibonacci(n-2)), it's exponentially
    // slow for anything past n=30 or so.
    //
    // Pseudocode:
    //   previous = 0
    //   current = 1
    //   repeat n times:
    //       next = previous + current
    //       previous = current
    //       current = next
    //   return previous
    throw std::logic_error("fibonacci: not implemented yet");
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
