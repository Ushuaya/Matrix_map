#include <gtest/gtest.h>

#include "../../src/Proxy.hpp"
#include "../../src/Matrix.hpp"
#include "../../src/Exceptions.hpp"


// compile with:
// g++ -std=c++17 Matrix_test.cpp -o test -lgtest -lgmock -pthread

class Proxy_test : public testing::Test { };

TEST(Proxy_test, Proxy_test_smth1_Test)
{
    Proxy<int> tmp;
    {
        Matrix<int> m2 = {{1, 2, 3}, {2, 3, 4}, {3, 4, 5}};
        Matrix_coords coor_in(1, 1, 2, -1);
        tmp = m2[coor_in];
    }
    ASSERT_THROW(std::cout << tmp, ExpiredElementException);
}

TEST(Proxy_test, Proxy_test_smth2_Test)
{
    Proxy<int> tmp;
    Matrix<int> m2 = {{1, 2, 3}, {2, 3, 4}, {3, 4, 5}};
    Matrix_coords coor_in_2(2, 2, -1, -1);
    tmp = m2[coor_in_2];
    EXPECT_NO_THROW(std::cout << tmp);
}

TEST(Proxy_test, Proxy_test_smth3_Test)
{
    Proxy<int> tmp;
    Matrix<int> m2 = {{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}};
    Matrix_coords coor_in_2(2, 2, -1, -1);
    tmp = m2[coor_in_2];
    ASSERT_NE(m2(2, 2), 5);
    tmp(0, 0) = 5;
    ASSERT_EQ(m2(2, 2), 5);
}

TEST(Proxy_test, Proxy_test_smth4_Test)
{
    Matrix<int> m2 = {{1, 2, 3}, {2, 3, 4}, {3, 4, 5}};
    Matrix_coords coor_in_2(2, 2, 5, 5);
    EXPECT_THROW(m2[coor_in_2], ProxyCoordsException);
}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}