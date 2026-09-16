#include "mathlib/mathlib.hpp"

#include <gtest/gtest.h>

using mathlib::average;
using mathlib::maxValue;
using mathlib::minValue;
using mathlib::percentile;

TEST(AverageTest, SingleElement) {
    EXPECT_DOUBLE_EQ(average({4.0}), 4.0);
}

TEST(AverageTest, SeveralPositiveElements) {
    EXPECT_DOUBLE_EQ(average({1.0, 2.0, 3.0, 4.0}), 2.5);
}

TEST(AverageTest, MixedPositiveAndNegative) {
    EXPECT_DOUBLE_EQ(average({-2.0, 2.0, 6.0}), 2.0);
}

TEST(AverageTest, Decimals) {
    EXPECT_DOUBLE_EQ(average({1.5, 2.5}), 2.0);
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
    EXPECT_DOUBLE_EQ(percentile({10.0, 20.0, 30.0, 40.0}, 0.0), 10.0);
}

TEST(PercentileTest, TwentyFifthPercentile) {
    EXPECT_DOUBLE_EQ(percentile({10.0, 20.0, 30.0, 40.0}, 25.0), 20.0);
}

TEST(PercentileTest, FiftiethPercentile) {
    EXPECT_DOUBLE_EQ(percentile({10.0, 20.0, 30.0, 40.0}, 50.0), 30.0);
}

TEST(PercentileTest, SeventyFifthPercentile) {
    EXPECT_DOUBLE_EQ(percentile({10.0, 20.0, 30.0, 40.0}, 75.0), 40.0);
}

TEST(PercentileTest, NearTopOfRange) {
    EXPECT_DOUBLE_EQ(
        percentile({10.0, 20.0, 30.0, 40.0, 50.0, 60.0, 70.0, 80.0, 90.0, 100.0}, 99.0), 100.0);
}
