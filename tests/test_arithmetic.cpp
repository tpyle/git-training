#include "mathlib/mathlib.hpp"

#include <gtest/gtest.h>

using mathlib::add;
using mathlib::divide;
using mathlib::multiply;
using mathlib::power;
using mathlib::subtract;

TEST(AddTest, PositivePlusPositive) {
    EXPECT_DOUBLE_EQ(add(2.0, 3.0), 5.0);
}

TEST(AddTest, PositivePlusNegative) {
    EXPECT_DOUBLE_EQ(add(5.0, -3.0), 2.0);
}

TEST(AddTest, WithZero) {
    EXPECT_DOUBLE_EQ(add(7.0, 0.0), 7.0);
}

TEST(SubtractTest, Basic) {
    EXPECT_DOUBLE_EQ(subtract(5.0, 3.0), 2.0);
}

TEST(SubtractTest, NegativeResult) {
    EXPECT_DOUBLE_EQ(subtract(3.0, 5.0), -2.0);
}

TEST(MultiplyTest, Basic) {
    EXPECT_DOUBLE_EQ(multiply(4.0, 3.0), 12.0);
}

TEST(MultiplyTest, ByZero) {
    EXPECT_DOUBLE_EQ(multiply(4.0, 0.0), 0.0);
}

TEST(MultiplyTest, NegativeTimesNegative) {
    EXPECT_DOUBLE_EQ(multiply(-4.0, -3.0), 12.0);
}

TEST(DivideTest, Basic) {
    EXPECT_DOUBLE_EQ(divide(10.0, 2.0), 5.0);
}

TEST(DivideTest, NegativeDivisor) {
    EXPECT_DOUBLE_EQ(divide(10.0, -2.0), -5.0);
}

TEST(DivideTest, DivideByZeroThrows) {
    EXPECT_THROW(divide(1.0, 0.0), std::invalid_argument);
}

TEST(PowerTest, ExponentZero) {
    EXPECT_DOUBLE_EQ(power(5.0, 0), 1.0);
}

TEST(PowerTest, ExponentOne) {
    EXPECT_DOUBLE_EQ(power(5.0, 1), 5.0);
}

TEST(PowerTest, PositiveMultiStep) {
    EXPECT_DOUBLE_EQ(power(2.0, 10), 1024.0);
}

TEST(PowerTest, NegativeBaseEvenExponent) {
    EXPECT_DOUBLE_EQ(power(-2.0, 4), 16.0);
}

TEST(PowerTest, NegativeBaseOddExponent) {
    EXPECT_DOUBLE_EQ(power(-2.0, 3), -8.0);
}

// TODO(trainee): implement negative exponents in mathlib::power, then remove
// the DISABLED_ prefix below and confirm this test passes.
TEST(PowerTest, DISABLED_NegativeExponent) {
    EXPECT_DOUBLE_EQ(power(2.0, -2), 0.25);
    EXPECT_DOUBLE_EQ(power(5.0, -1), 0.2);
}
