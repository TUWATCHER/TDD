#include <iostream>
#include <string>

#include "googletest/googletest/include/gtest/gtest.h"
#include "googletest/googlemock/include/gmock/gmock.h"


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

std::string ConvertArabic(const unsigned int number)
{
    return "";
}

TEST(ArabicToNumeral, Convert_1)
{
    ASSERT_EQ("I", ConvertArabic(1));
}

TEST(ArabicToNumeral, PreparationsComplete)
{
    GTEST_FAIL();
}