#include <gtest/gtest.h>
#include "temp.h"

TEST(FailureDemo, ExpectContinues)
{
    EXPECT_EQ(original::toFahrenheit(0), 0);
    EXPECT_EQ(original::toFahrenheit(10), 0);
}

TEST(FailureDemo, AssertStops)
{
    ASSERT_EQ(original::toFahrenheit(0), 0);
    EXPECT_EQ(original::toFahrenheit(10), 0);
}
