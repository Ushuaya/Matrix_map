#include <gtest/gtest.h>
#include "../../src/Strint.hpp"
// compile with:
// g++ -std=c++17 StrInt_test.cpp -o test -lgtest -lgmock -pthread

class StringInt_test : public testing::Test { };

TEST(StringInt_test, StringInt_test_smth1_Test)
{
    StrInt num;

    num = StrInt("+123");
    ASSERT_EQ(num.get_sign(), '+');
    ASSERT_EQ(num.get_val(), "123");

    num = StrInt("-123");
    ASSERT_EQ(num.get_sign(), '-');
    ASSERT_EQ(num.get_val(), "123");

    num = StrInt("123");
    ASSERT_EQ(num.get_sign(), '+');
    ASSERT_EQ(num.get_val(), "123");
}

TEST(StringInt_test, StringInt_test_smth2_Test)
{

    // std::cout << StrInt::plus_str("123", "1") << std::endl;
    // std::cout << StrInt::plus_str("100", "1454") << std::endl;
    ASSERT_EQ(StrInt::plus_str("123", "1"), "124");
    ASSERT_EQ(StrInt::plus_str("100", "1454"), "1554");
    ASSERT_EQ(StrInt::plus_str("99", "99"), "198");
    ASSERT_EQ(StrInt::minus_str("0", "99"), "99");
    ASSERT_EQ(StrInt::minus_str("988", "99"), "889");

}

TEST(StringInt_test, StringInt_test_smth3_Test)
{
    StrInt d1 = StrInt("+123");
    StrInt d2 = StrInt("-123");
    ASSERT_EQ(d1.get_val(), "123");
    ASSERT_EQ(d2.get_val(), "123");
    ASSERT_EQ(d1.get_sign(), '+');
    ASSERT_EQ(d2.get_sign(), '-');


    d1 = StrInt("3");
    d2 = StrInt("67");
    ASSERT_EQ(d1-d2, StrInt(-64));
    d1 = StrInt("-3");
    d2 = StrInt("-67");
    ASSERT_EQ(d1-d2, StrInt(64));
    d1 = StrInt("+3");
    d2 = StrInt("-67");
    ASSERT_EQ(d1-d2, StrInt(70));
    d1 = StrInt("-3");
    d2 = StrInt("+67");
    ASSERT_EQ(d1-d2, StrInt(-70));
    d1 = StrInt("3");
    d2 = StrInt("67");
    // ASSERT_EQ(d1+d2, StrInt(0));
    // ASSERT_EQ((d1 - d2), StrInt(-64));
    // ASSERT_EQ(d1+d2, StrInt(0));
    // ASSERT_EQ(d1+d2, StrInt(0));
}

TEST(StringInt_test, StringInt_test_smth4_Test)
{
    StrInt d1 = StrInt("+1");
    StrInt d2 = StrInt("+2");
    ASSERT_EQ((d1.get_val() < d2.get_val()), StrInt::cmpr::smaller);
    ASSERT_EQ((d2.get_val() < d1.get_val()), StrInt::cmpr::bigger);
    d1 = d2;
    ASSERT_EQ((d2.get_val() < d1.get_val()), StrInt::cmpr::equal);
}

TEST(StringInt_test, StringInt_test_smth5_Test)
{
    auto d1 = StrInt("3");
    auto d2 = StrInt("67");
    ASSERT_EQ(d1*d2, StrInt(201));
    d1 = StrInt("-3");
    d2 = StrInt("-67");
    ASSERT_EQ(d1*d2, StrInt(201));
    d1 = StrInt("+3");
    d2 = StrInt("-67");
    ASSERT_EQ(d1*d2, StrInt(-201));
    d1 = StrInt("-3");
    d2 = StrInt("+67");
    ASSERT_EQ(d1*d2, StrInt(-201));
}

TEST(StringInt_test, StringInt_test_smth6_Test)
{
    auto d1 = StrInt("67");
    auto d2 = StrInt("3");
    ASSERT_EQ(d1/d2, StrInt(22));
    d1 = StrInt("-67");
    d2 = StrInt("-3");
    ASSERT_EQ(d1/d2, StrInt(22));
    d1 = StrInt("+67");
    d2 = StrInt("-3");
    ASSERT_EQ(d1/d2, StrInt(-22));
    d1 = StrInt("-67");
    d2 = StrInt("+3");
    ASSERT_EQ(d1/d2, StrInt(-22));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}