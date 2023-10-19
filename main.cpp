#include <iostream>
#include <string>

#include "googletest/googletest/include/gtest/gtest.h"
#include "googletest/googlemock/include/gmock/gmock.h"

std::string ConvertArabic(unsigned int number);

class RomanNumeralAssert
{
    public:

        RomanNumeralAssert() = delete;
        explicit RomanNumeralAssert(const unsigned int arabicNumeral) :
            arabicNumberToConvert(arabicNumeral) {}
        void isConvertedToRomanNumeral(const std::string& ExpectedRomanNumeral) const
        {
            ASSERT_EQ(ExpectedRomanNumeral, ConvertArabic(arabicNumberToConvert));
        }
    
    private:
        const unsigned int arabicNumberToConvert;
};

RomanNumeralAssert assertThat(const unsigned int arabicNumber)
{
    RomanNumeralAssert assert { arabicNumber };
    return assert;
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
   // std::cout << ConvertArabic(23);
    return RUN_ALL_TESTS();
}

std::string ConvertArabic(unsigned int number)
{
    std::string romanNumeral;
    while(number >= 100)
    {
        romanNumeral += "C";
        number -= 100;
    }
    while(number >= 10)
    {
        romanNumeral += "X";
        number -= 10;
    }
    
    while(number >= 1)
    {
        romanNumeral += "I";
        number--;
    }
    
    return romanNumeral;
}

TEST(ArabicToNumeral, ConversionTestCases)
{
    assertThat(1).isConvertedToRomanNumeral("I");
    assertThat(2).isConvertedToRomanNumeral("II");
    assertThat(3).isConvertedToRomanNumeral("III");
    assertThat(10).isConvertedToRomanNumeral("X");
    assertThat(20).isConvertedToRomanNumeral("XX");
    assertThat(30).isConvertedToRomanNumeral("XXX");
    assertThat(33).isConvertedToRomanNumeral("XXXIII");
    assertThat(100).isConvertedToRomanNumeral("C");
    assertThat(200).isConvertedToRomanNumeral("CC");
    assertThat(300).isConvertedToRomanNumeral("CCC");
}
