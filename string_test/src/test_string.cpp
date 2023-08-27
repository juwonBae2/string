#include "string.hpp"
// TODO: Console style 아직 정용 x
// #include "console_style.hpp"

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#include <gtest/gtest.h>

#define PRINTLN(...)          \
    std::cout << "\033[1;4m"; \
    fmt::print(__VA_ARGS__);  \
    std::cout << "\033[0m\n";

class StringTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
    }

    void TearDown() override
    {
    }
};

TEST_F(StringTest, Concatenation)
{
    String str1 = "Hello";
    String str2 = "World";
    String str3 = str1 + str2;

    ASSERT_EQ(String("HelloWorld"), str3);
}

TEST_F(StringTest, ComparisonLessThan)
{
    String str1 = "A";
    String str2 = "a";
    ASSERT_TRUE(str1 < str2);
}

TEST_F(StringTest, ComparisonNotGreaterThan)
{
    String str1 = "Hello";
    String str2 = "World";
    ASSERT_FALSE(str1 > str2);
}

TEST_F(StringTest, ComparisonEqualityAndInequality)
{
    String str1 = "Hello";
    String str2 = "World";
    ASSERT_FALSE(str1 == str2);

    String str_eq1 = "same one";
    String str_eq2 = "same one";
    ASSERT_TRUE(str_eq1 == str_eq2);
}

TEST_F(StringTest, ComparisonNotEqual)
{
    String str1 = "Hello";
    String str2 = "World";
    ASSERT_TRUE(str1 != str2);
}

TEST_F(StringTest, PrintFrontLetter)
{
    String name = "Juwon Bae";
    auto printFront = name.front();
    PRINTLN("User name: {}", name);
    PRINTLN("Name print first letter: {}", printFront);
    ASSERT_EQ(String("J"), printFront);
}

TEST_F(StringTest, PrintBackLetter)
{
    String name = "Juwon Bae";
    auto printBack = name.back();
    PRINTLN("User name: {}", name);
    PRINTLN("Name print last letter: {}", printBack);
    ASSERT_EQ(String("e"), printBack);
}

TEST_F(StringTest, TrimFunction)
{
    String str1 = "   Hello world   ";
    String trimmed1 = str1.trim();
    ASSERT_EQ(String("Helloworld"), trimmed1);

    String str2 = "       ";
    ASSERT_EQ(String("       "), str2);
    String trimmed2 = str2.trim();
    ASSERT_EQ(String(""), trimmed2);

    String str3 = "HelloWorld";
    String trimmed3 = str3.trim();
    ASSERT_EQ(String("HelloWorld"), trimmed3);

    String str4;
    String trimmed4 = str4.trim();
    ASSERT_EQ(String(""), trimmed4);
}

TEST_F(StringTest, EraseFunction)
{
    // str lenght = 13
    String str = "Hello, World!";

    // Erase "World"
    String erased1 = str.erase(7, 5);
    ASSERT_EQ(String("Hello, !"), erased1);

    // Erase "Hello, "
    String erased2 = str.erase(0, 6);
    ASSERT_EQ(String(" World!"), erased2);

    // Erase entire string
    String erased3 = str.erase(0, 13);
    ASSERT_EQ(String(""), erased3);

    // Erase more than length
    String erased4 = str.erase(0, 20);
    ASSERT_NE(String("Hello, World!"), erased4);

    // Erase from out-of-bounds index
    String erased5 = str.erase(15, 3);
    ASSERT_EQ(String("Hello, World!"), erased5);

    String emptyStr;
    String erased6 = emptyStr.erase(0, 1);
    ASSERT_EQ(String(""), erased6);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}