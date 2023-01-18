#include <gtest/gtest.h>

#include "../../src/Inputer.hpp"
#include "../../src/Matrix.hpp"

// compile with:
// g++ -std=c++17 Matrix_test.cpp -o test -lgtest -lgmock -pthread

class Matrix_test : public testing::Test { };

// TEST(Matrix_test, Matrix_test_smth1_Test)
// {
//     // Vector<Rational_number> new_vector = Inputer<Rational_number>().input_Vector("./Vector_Rational.txt");
//     // std::cout << new_vector << std::endl << std::endl;
//     std::cout << std::string(std::filesystem::current_path()) << "\n";
//     Matrix<Rational_number> mtx1 = Inputer<Rational_number>().input_Matrix(std::string(std::filesystem::current_path()) + "/Matrix_Rational.txt");

//     Matrix<Rational_number> mtx2 = {{1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}};

//     // std::cout << new_vector << std::endl;
//     std::cout << mtx1 << std::endl << std::endl;
//     std::cout << mtx2 << std::endl << std::endl;

//     //ASSERT_EQ(mtx1, mtx2);
//     ASSERT_EQ(mtx1.to_string(), mtx2.to_string());
// }

// TEST(Vector_test, smth1)
// {
//     Vector<Rational_number> new_vector_1 = Inputer<Rational_number>().input_Vector("./Vector_Rational.txt");
//     Vector<Rational_number> new_vector_2 = Inputer<Rational_number>().input_Vector("./Vector_Rational.txt");
//     //std::cout << new_vector << std::endl << std::endl;
//     ASSERT_EQ((new_vector_1 + new_vector_1).to_string(), (new_vector_2 + new_vector_2).to_string());
// }

TEST(Vector_test, smth2)
{
    EXPECT_ANY_THROW(Inputer<Rational_number>().input_Vector("./Vector_Rational_wrong_1.txt"));
    
    //std::cout << new_vector << std::endl << std::endl;
   // ASSERT_EQ((new_vector_1 + new_vector_1).to_string(), (new_vector_2 + new_vector_2).to_string());
}


TEST(Matrix_test, Matrix_test_smth2_Test)
{
    EXPECT_ANY_THROW(Inputer<Rational_number>().input_Matrix("./Matrix_Rational_wrong_1.txt"));
}

TEST(Matrix_test, Matrix_test_smth3_Test)
{
    EXPECT_ANY_THROW(Inputer<Rational_number>().input_Matrix("./Matrix_Rational_wrong_2.txt"));
}

TEST(Matrix_test, Matrix_test_smth4_Test)
{
    EXPECT_ANY_THROW(Inputer<Rational_number>().input_Matrix("./Matrix_Rational_wrong_3.txt"));
}


TEST(Matrix_test, Matrix_test_smth5_Test)
{
    EXPECT_ANY_THROW(Inputer<Rational_number>().input_Matrix("./Matrix_Rational_wrong_4.txt"));
}

TEST(Matrix_test, Matrix_test_smth6_Test)
{
    EXPECT_ANY_THROW(Inputer<Rational_number>().input_Matrix("./Matrix_Rational_wrong_5.txt"));
}


TEST(Matrix_test, Matrix_test_smth7_Test)
{
    EXPECT_ANY_THROW(Inputer<Rational_number>().input_Matrix("./Matrix_Rational_wrong_3.txt"));
}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}