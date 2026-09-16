#include "mathlib/mathlib.hpp"

#include <gtest/gtest.h>

using mathlib::average;
using mathlib::maxValue;
using mathlib::minValue;
using mathlib::percentile;

TEST(AverageTest, SingleElement) {
    double values[] = {4.0};
    EXPECT_DOUBLE_EQ(average(values, 1), 4.0);
}

TEST(AverageTest, SeveralPositiveElements) {
    double values[] = {1.0, 2.0, 3.0, 4.0};
    EXPECT_DOUBLE_EQ(average(values, 4), 2.5);
}

TEST(AverageTest, MixedPositiveAndNegative) {
    double values[] = {-2.0, 2.0, 6.0};
    EXPECT_DOUBLE_EQ(average(values, 3), 2.0);
}

TEST(AverageTest, Decimals) {
    double values[] = {1.5, 2.5};
    EXPECT_DOUBLE_EQ(average(values, 2), 2.0);
}

TEST(MinValueTest, ALessThanB) {
    EXPECT_DOUBLE_EQ(minValue(2.0, 5.0), 2.0);
}

TEST(MinValueTest, AGreaterThanB) {
    EXPECT_DOUBLE_EQ(minValue(5.0, 2.0), 2.0);
}

TEST(MinValueTest, AEqualsB) {
    EXPECT_DOUBLE_EQ(minValue(3.0, 3.0), 3.0);
}

TEST(MinValueTest, Negatives) {
    EXPECT_DOUBLE_EQ(minValue(-5.0, -2.0), -5.0);
}

TEST(MaxValueTest, ALessThanB) {
    EXPECT_DOUBLE_EQ(maxValue(2.0, 5.0), 5.0);
}

TEST(MaxValueTest, AGreaterThanB) {
    EXPECT_DOUBLE_EQ(maxValue(5.0, 2.0), 5.0);
}

TEST(MaxValueTest, AEqualsB) {
    EXPECT_DOUBLE_EQ(maxValue(3.0, 3.0), 3.0);
}

TEST(MaxValueTest, Negatives) {
    EXPECT_DOUBLE_EQ(maxValue(-5.0, -2.0), -2.0);
}

TEST(PercentileTest, ZerothPercentile) {
    double values[] = {10.0, 20.0, 30.0, 40.0};
    EXPECT_DOUBLE_EQ(percentile(values, 4, 0.0), 10.0);
}

TEST(PercentileTest, TwentyFifthPercentile) {
    double values[] = {10.0, 20.0, 30.0, 40.0};
    EXPECT_DOUBLE_EQ(percentile(values, 4, 25.0), 20.0);
}

TEST(PercentileTest, FiftiethPercentile) {
    double values[] = {10.0, 20.0, 30.0, 40.0};
    EXPECT_DOUBLE_EQ(percentile(values, 4, 50.0), 30.0);
}

TEST(PercentileTest, SeventyFifthPercentile) {
    double values[] = {10.0, 20.0, 30.0, 40.0};
    EXPECT_DOUBLE_EQ(percentile(values, 4, 75.0), 40.0);
}

TEST(PercentileTest, NearTopOfRange) {
    double values[] = {10.0, 20.0, 30.0, 40.0, 50.0, 60.0, 70.0, 80.0, 90.0, 100.0};
    EXPECT_DOUBLE_EQ(percentile(values, 10, 99.0), 100.0);
}

// There's a bug lurking in mathlib::percentile right at the top of its
// range. Uncomment this test and rerun the suite to see it for yourself
// (see README Module 6 for how to track down which commit caused it).
// TEST(PercentileTest, HundredthPercentile) {
//     double values[] = {10.0, 20.0, 30.0, 40.0};
//     EXPECT_DOUBLE_EQ(percentile(values, 4, 100.0), 40.0);
// }
