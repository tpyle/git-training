#pragma once

#include <cstddef>

/**
 * A small, intentionally simple math library used for training purposes.
 * Some functions below are fully implemented, some are left as stubs on
 * purpose (they throw std::logic_error) so folks can practice implementing
 * them. Feel free to poke at any of this.
 */
namespace mathlib {

/** Returns a + b. */
double add(double a, double b);

/** Returns a - b. */
double subtract(double a, double b);

/** Returns a * b. */
double multiply(double a, double b);

/**
 * Returns numerator / denominator.
 * Throws std::invalid_argument if denominator is 0.
 */
double divide(double numerator, double denominator);

/**
 * Raises base to the given integer exponent.
 * Negative exponents are not implemented yet - see the source file.
 * Throws std::logic_error if exponent is negative.
 */
double power(double base, int exponent);

/** Returns the smaller of a and b. */
double minValue(double a, double b);

/** Returns the larger of a and b. */
double maxValue(double a, double b);

/**
 * Computes the arithmetic mean of the given values.
 * values must point to at least count doubles, and count must be non-zero.
 */
double average(const double* values, std::size_t count);

/**
 * Returns the value at the given percentile of a sorted array.
 * sortedValues must point to count doubles sorted in ascending order.
 * percentile must be in [0, 100].
 */
double percentile(const double* sortedValues, std::size_t count, double percentile);

/**
 * Computes the greatest common divisor of a and b.
 * Not implemented yet - this is a training exercise. See the pseudocode for
 * Euclid's algorithm in the comment above this function in mathlib.cpp.
 * Throws std::logic_error always, for now.
 */
long gcd(long a, long b);

/**
 * Computes the least common multiple of a and b.
 * Not implemented yet - this is a training exercise. It's a one-line
 * formula once mathlib::gcd works - see the comment in mathlib.cpp.
 * Throws std::logic_error always, for now.
 */
long lcm(long a, long b);

/**
 * Returns true if n is a prime number.
 * Not implemented yet - this is a training exercise (trial division is fine).
 * Throws std::logic_error always, for now.
 */
bool isPrime(long n);

/**
 * Computes n! (n factorial).
 * Throws std::invalid_argument if n > 20, since the result would overflow
 * unsigned long long.
 */
unsigned long long factorial(unsigned int n);

/**
 * Returns the nth Fibonacci number (fibonacci(0) == 0, fibonacci(1) == 1).
 * Not implemented yet - this is a training exercise. See the pseudocode in
 * mathlib.cpp - implement it iteratively, not with naive recursion.
 * Throws std::logic_error always, for now.
 */
unsigned long long fibonacci(unsigned int n);

/**
 * Returns true if n is a perfect square (0, 1, 4, 9, 16, ...).
 * Not implemented yet - this is a training exercise. See the pseudocode in
 * mathlib.cpp - avoid floating-point sqrt(), it can round the wrong way
 * right at the boundary.
 * Throws std::logic_error always, for now.
 */
bool isPerfectSquare(long n);

}  // namespace mathlib
