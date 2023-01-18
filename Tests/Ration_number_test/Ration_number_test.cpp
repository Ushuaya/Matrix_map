#include <gtest/gtest.h>
#include "../../src/Rational_number.hpp"
// compile with:
// g++ -std=c++17 StrInt_test.cpp -o test -lgtest -lgmock -pthread

class Rational_number_test : public testing::Test { };

TEST(Rational_number_test, Rational_number_test_smth1_Test)
{
    Rational_number r1("-3", "5");
    Rational_number r2(StrInt("4"), StrInt("8"));
    //std::cout << (r1 + r2) << std::endl;
    ASSERT_EQ((r1 + r2).to_string(), Rational_number("-1","10").to_string());
    //std::cout << (-r1 + r2) << std::endl;
    ASSERT_EQ((-r1 + r2).to_string(), Rational_number("11/10").to_string());
    //std::cout << (-r1 - r2) << std::endl;
    ASSERT_EQ((-r1 - r2).to_string(), Rational_number("1/10").to_string());
    //std::cout << (r1 - r2) << std::endl;
    ASSERT_EQ((r1 - r2).to_string(), Rational_number("-11/10").to_string());
}

TEST(Rational_number_test, Rational_number_test_smth2_Test)
{
    Rational_number r1("-3", "5");
    Rational_number r2(StrInt("4"), StrInt("8"));
    //std::cout << (r1 + r2) << std::endl;
    ASSERT_EQ((r1 * r2).to_string(), Rational_number("3","-10").to_string());
    //std::cout << (-r1 + r2) << std::endl;
    ASSERT_EQ((-r1 * r2).to_string(), Rational_number("3/10").to_string());
    //std::cout << (-r1 - r2) << std::endl;
    ASSERT_EQ((r1 * -r2).to_string(), Rational_number("0.3").to_string());
    //std::cout << (r1 - r2) << std::endl;
    ASSERT_EQ((-r1 * -r2).to_string(), Rational_number("-3/10").to_string());
}

TEST(Rational_number_test, Rational_number_test_smth3_Test)
{
    Rational_number r1("-3", "5");
    Rational_number r2(StrInt("4"), StrInt("8"));
    //std::cout << (r1 + r2) << std::endl;
    ASSERT_EQ((r1 / r2).to_string(), Rational_number("3","-5").to_string());
    //std::cout << (-r1 + r2) << std::endl;
    ASSERT_EQ((-r1 / r2).to_string(), Rational_number("3/5").to_string());
    //std::cout << (-r1 - r2) << std::endl;
    ASSERT_EQ((r1 / -r2).to_string(), Rational_number("0.6").to_string());
    //std::cout << (r1 - r2) << std::endl;
    ASSERT_EQ((-r1 / -r2).to_string(), Rational_number("-3/5").to_string());

}

TEST(Rational_number_test, Rational_number_test_smth4_Test)
{
    Rational_number r3("-3.500");
    Rational_number r4("+4.5000000");
    ASSERT_EQ((r3 + r4).to_string(), Rational_number(StrInt(1)).to_string());

}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}