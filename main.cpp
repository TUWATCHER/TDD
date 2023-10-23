#include <iostream>
#include <string>
#include <array>


struct ArabicToRomanMap
{
    unsigned int arabicNumber;
    std::string romanNumber;    
};

std::string ConvertArabic(unsigned int number);

int main()
{
    std::cout << ConvertArabic(564);

    return 0;
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


