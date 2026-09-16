#include "mathlib/mathlib.hpp"

#include <gtest/gtest.h>

using mathlib::factorial;
using mathlib::gcd;
using mathlib::isPrime;

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

// TODO(trainee): implement mathlib::gcd (Euclid's algorithm), then remove
// the DISABLED_ prefix below and confirm this test passes.
TEST(GcdTest, DISABLED_Basic) {
    EXPECT_EQ(gcd(12, 18), 6);
    EXPECT_EQ(gcd(0, 5), 5);
    EXPECT_EQ(gcd(17, 5), 1);
    EXPECT_EQ(gcd(-4, 6), 2);
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
