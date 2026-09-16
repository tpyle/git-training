#pragma once

#include <vector>

/// A small, intentionally simple math library used for training purposes.
/// Some functions below are fully implemented, some are left as stubs on
/// purpose (they throw std::logic_error) so folks can practice implementing
/// them. Feel free to poke at any of this.
namespace mathlib {

/// Returns a + b.
double add(double a, double b);

/// Returns a - b.
double subtract(double a, double b);

/// Returns a * b.
double multiply(double a, double b);

/// Returns numerator / denominator.
/// @throws std::invalid_argument if denominator is 0.
double divide(double numerator, double denominator);

/// Raises base to the given integer exponent.
/// Negative exponents are not implemented yet - see the source file.
/// @throws std::logic_error if exponent is negative.
double power(double base, int exponent);

/// Returns the smaller of a and b.
double minValue(double a, double b);

/// Returns the larger of a and b.
double maxValue(double a, double b);

/// Computes the arithmetic mean of values.
/// @param values A non-empty list of numbers to average.
/// @return The arithmetic mean of all elements in values.
double average(const std::vector<double>& values);

/// Computes the greatest common divisor of a and b.
/// Not implemented yet - this is a training exercise.
/// @throws std::logic_error always, for now.
long gcd(long a, long b);

/// Returns true if n is a prime number.
/// Not implemented yet - this is a training exercise.
/// @throws std::logic_error always, for now.
bool isPrime(long n);

/// Computes n! (n factorial).
/// @throws std::invalid_argument if n > 20, since the result would overflow
///   unsigned long long.
unsigned long long factorial(unsigned int n);

}  // namespace mathlib
