#include "string_implementation.hpp"
#include <gtest/gtest.h>
class StringTest : public ::testing::Test
{
protected:
    int argc;
    char **argv;

    void SetUp() override
    {
        ::testing::InitGoogleTest(&argc, argv);
    }

    void TearDown() override
    {
        return RUN_ALL_TESTS();
    }
};

TEST_F(StringTest, Concatenation)
{
    String str1 = "Hello";
    String str2 = "World";
    String str3 = str1 + str2;

    ASSERT_EQ("HelloWorld", str3);
}

// TEST_F(StringTest, Comparison)
// {
//     String str1 = "Hello";
//     String str2 = "World";

//     EXPECT_TRUE(str1 < str2);
//     EXPECT_FALSE(str1 == str2);
//     EXPECT_FALSE(str1 > str2);
// }

// // TODO: test 코드 참고용
// #include "string_implementation.hpp"

// int main()
// {
//     String str1 = "Hello";
//     std::cout << "Concatenated string(str1): " << str1 << std::endl;

//     String str2 = "World";

//     String str3 = str1 + str2;
//     std::cout << "Concatenated string: " << str3 << std::endl;

//     if (str1 == str2)
//     {
//         std::cout << "str1 and str2 are equal." << std::endl;
//     }
//     else if (str1 < str2)
//     {
//         std::cout << "str1 is less than str2." << std::endl;
//     }
//     else if (str1 > str2)
//     {
//         std::cout << "str1 is greater than str2." << std::endl;
//     }

//     return 0;
// }