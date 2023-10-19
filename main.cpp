#include <iostream>
#include <string>
#include <array>

#include "googletest/googletest/include/gtest/gtest.h"
#include "googletest/googlemock/include/gmock/gmock.h"

std::string ConvertArabic(unsigned int number);
struct ArabicToRomanMap
{
    unsigned int arabicNumber;
    std::string romanNumber;
};
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
    const std::size_t numberofMappings = 13;
    using mapping = std::array<ArabicToRomanMap, numberofMappings>;
    const mapping ArabicRomanMap =
    {{
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"}
    }};
    std::string romanNumeral;
    for (const auto& mapp : ArabicRomanMap)
    {
        while (number >= mapp.arabicNumber)
        {
            romanNumeral += mapp.romanNumber;
            number -= mapp.arabicNumber;
        }
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
    assertThat(500).isConvertedToRomanNumeral("D");
    assertThat(1000).isConvertedToRomanNumeral("M");
    assertThat(2000).isConvertedToRomanNumeral("MM");
    assertThat(3000).isConvertedToRomanNumeral("MMM");
    assertThat(3333).isConvertedToRomanNumeral("MMMCCCXXXIII");
    assertThat(3999).isConvertedToRomanNumeral("MMMCMXCIX");
    assertThat(5).isConvertedToRomanNumeral("V");
    assertThat(6).isConvertedToRomanNumeral("VI");
    assertThat(4).isConvertedToRomanNumeral("IV");

}
