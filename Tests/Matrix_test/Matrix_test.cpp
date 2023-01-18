#include <gtest/gtest.h>
#include "../../src/Matrix.hpp"
// compile with:
// g++ -std=c++17 Matrix_test.cpp -o test -lgtest -lgmock -pthread

class Matrix_test : public testing::Test { };

TEST(Matrix_test, Matrix_test_smth1_Test)
{
    Matrix<int> m;
    ASSERT_EQ(m.get_size(), 0);
    ASSERT_EQ(m.get_n(), 10);
    ASSERT_EQ(m.get_m(), 10);
    m(5, 4) = 5;
    ASSERT_EQ(m(5, 4), 5);
    ASSERT_EQ(m.get_size(), 1);

}

TEST(Matrix_test, smth2) {
    Matrix<Rational_number> m = Matrix<Rational_number>();
    ASSERT_EQ(m.get_size(), 0);
    m(5, 4) = Rational_number("5/12");
    ASSERT_EQ(m(5, 4), Rational_number(5, 12));
    ASSERT_EQ(m.get_size(), 1);
}



int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}