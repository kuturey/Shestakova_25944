#include <gtest/gtest.h>
#include "temp.h"

TEST(TemplateOriginalTests, IntValue)
{
    EXPECT_EQ(original::toFahrenheit(10), 50);
}

TEST(TemplateOriginalTests, DoubleValue)
{
    EXPECT_DOUBLE_EQ(original::toFahrenheit(10.0), 50.0);
}

TEST(TemplateModifiedTests, IntRange)
{
    int value = 10;
    int result = modified::toFahrenheit(value);

    EXPECT_GE(result, 40);
    EXPECT_LE(result, 60);
}

TEST(TemplateModifiedTests, DoubleRange)
{
    double value = 10.0;
    double result = modified::toFahrenheit(value);

    EXPECT_GE(result, 40.0);
    EXPECT_LE(result, 60.0);
}
