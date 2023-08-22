#include "string.hpp"
#include <gtest/gtest.h>
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

TEST_F(StringTest, Operator)
{
    String str1 = "A";
    String str2 = "a";
    ASSERT_TRUE(str1 < str2);
}

TEST_F(StringTest, Operator2)
{
    String str1 = "Hello";
    String str2 = "World";
    ASSERT_FALSE(str1 > str2);
}

TEST_F(StringTest, Operator3)
{
    // TODO: 에러 코드 return하도록 추가
    String str1 = "Hello";
    String str2 = "World";
    ASSERT_FALSE(str1 == str2);

    String str_eq1 = "same one";
    String str_eq2 = "same one";
    ASSERT_TRUE(str_eq1 == str_eq2);
}

TEST_F(StringTest, Operator4)
{
    String str1 = "Hello";
    String str2 = "World";
    ASSERT_TRUE(str1 != str2);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}