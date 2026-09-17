#include "mathlib/mathlib.hpp"

#include <gtest/gtest.h>

using mathlib::factorial;
using mathlib::fibonacci;
using mathlib::gcd;
using mathlib::isPerfectSquare;
using mathlib::isPrime;
using mathlib::lcm;

TEST(FactorialTest, Zero) {
    EXPECT_EQ(factorial(0), 1ULL);
}

TEST(FactorialTest, One) {
    EXPECT_EQ(factorial(1), 1ULL);
}

TEST(FactorialTest, Five) {
    EXPECT_EQ(factorial(5), 120ULL);
}

TEST(FactorialTest, Twenty) {
    EXPECT_EQ(factorial(20), 2432902008176640000ULL);
}

TEST(FactorialTest, TooLargeThrows) {
    EXPECT_THROW(factorial(21), std::invalid_argument);
}

// TODO(trainee): implement mathlib::gcd (Euclid's algorithm - there's
// pseudocode in the comment above it in mathlib.cpp), then remove the
// DISABLED_ prefix below and confirm this test passes.
TEST(GcdTest, Basic) {
    EXPECT_EQ(gcd(12, 18), 6);
    EXPECT_EQ(gcd(0, 5), 5);
    EXPECT_EQ(gcd(17, 5), 1);
    EXPECT_EQ(gcd(-4, 6), 2);
}

// TODO(trainee): implement mathlib::lcm (needs mathlib::gcd working first -
// see the comment in mathlib.cpp), then remove the DISABLED_ prefix below
// and confirm this test passes.
TEST(LcmTest, DISABLED_Basic) {
    EXPECT_EQ(lcm(4, 6), 12);
    EXPECT_EQ(lcm(21, 6), 42);
    EXPECT_EQ(lcm(5, 5), 5);
    EXPECT_EQ(lcm(0, 5), 0);
}

// TODO(trainee): implement mathlib::isPrime, then remove the DISABLED_
// prefix below and confirm this test passes.
TEST(IsPrimeTest, DISABLED_Basic) {
    EXPECT_TRUE(isPrime(2));
    EXPECT_FALSE(isPrime(1));
    EXPECT_FALSE(isPrime(0));
    EXPECT_TRUE(isPrime(17));
    EXPECT_FALSE(isPrime(18));
    EXPECT_FALSE(isPrime(-7));
}

// TODO(trainee): implement mathlib::fibonacci iteratively (there's
// pseudocode in the comment above it in mathlib.cpp), then remove the
// DISABLED_ prefix below and confirm this test passes.
TEST(FibonacciTest, DISABLED_Basic) {
    EXPECT_EQ(fibonacci(0), 0ULL);
    EXPECT_EQ(fibonacci(1), 1ULL);
    EXPECT_EQ(fibonacci(2), 1ULL);
    EXPECT_EQ(fibonacci(10), 55ULL);
}

// TODO(trainee): implement mathlib::isPerfectSquare (there's pseudocode in
// the comment above it in mathlib.cpp), then remove the DISABLED_ prefix
// below and confirm this test passes.
TEST(IsPerfectSquareTest, DISABLED_Basic) {
    EXPECT_TRUE(isPerfectSquare(0));
    EXPECT_TRUE(isPerfectSquare(1));
    EXPECT_TRUE(isPerfectSquare(16));
    EXPECT_FALSE(isPerfectSquare(15));
    EXPECT_FALSE(isPerfectSquare(-4));
}
