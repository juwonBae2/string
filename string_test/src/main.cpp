#include "string_implementation.hpp"

// TODO: void Setup() override, void TearDown() override 로 수정
int main()
{
    String str1 = "Hello";
    std::cout << "Concatenated string(str1): " << str1 << std::endl;

    String str2 = "World";

    String str3 = str1 + str2;
    std::cout << "Concatenated string: " << str3 << std::endl;

    if (str1 == str2)
    {
        std::cout << "str1 and str2 are equal." << std::endl;
    }
    else if (str1 < str2)
    {
        std::cout << "str1 is less than str2." << std::endl;
    }
    else if (str1 > str2)
    {
        std::cout << "str1 is greater than str2." << std::endl;
    }

    return 0;
}