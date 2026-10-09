#include <gtest/gtest.h>
#include "temp.h"

TEST(OriginalTests, Zero)
{
    EXPECT_EQ(original::toFahrenheit(0), 32);
}

TEST(OriginalTests, Ten)
{
    EXPECT_EQ(original::toFahrenheit(10), 50);
}

TEST(ModifiedTests, ResultIsInAllowedRange)
{
    int value = 10;
    int result = modified::toFahrenheit(value);

    EXPECT_GE(result, 40);
    EXPECT_LE(result, 60);
}
