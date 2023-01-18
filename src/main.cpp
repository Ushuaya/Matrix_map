//
//  main.cpp
//  task1.cpp
//
//  Created by VolkSeriy on 12.09.2022.
//
#include <iostream>
#include <string>
#include <iomanip>
#include <utility>
#include <iostream>
#include <stdexcept>
#include <map>
#include <string>
#include <vector>
#include <numeric>
#include <fstream>

#include "Proxy.hpp"
//#include "Proxy.cpp"
#include "Matrix.hpp"
//#include "Matrix.cpp"
#include "Vector.hpp"
//#include "Vector.cpp"
//#include "Strint.hpp"
#include "Rational_number.hpp"
#include "Inputer.hpp"
#include "Exceptions.hpp"
#include "Matrix_coords.hpp"






//class Rational_number
//{
//    private:
//        std::string top;
//        std::string bottom;
//    public:
//
//};



int main()
{
    try{
    //std::cout << std::gcd(1, 2) << std::endl;
    
        
        //auto r1 = Rational_number("1", "0");
    //Vector<T>::Vector(int size);
//    Vector<int> v1 (5);
//    Vector<int> v2 (5);
//    std::cout << "(v1 == v2): " << (v1 == v2) << std::endl;
//    std::cout << "(v1 != v2): " << (v1 != v2) << std::endl;
//    std::cout << "(v1 + v2): " << (v1 + v2) << std::endl;
//    std::cout << "(v1 - v2): " << (v1 - v2) << std::endl;
//    std::cout << "(v1 * 2): " << (v1 * 2) << std::endl;
    //Matrix<int> m1 (2, 3);
//    Matrix<int> m2 (2, 3);
//    std::cout << "(m1 + m2): " << std::endl << (m1 + m2) << std::endl;
//    std::cout << "(m1 - m2): " << std::endl << (m1 - m2) << std::endl;
//    std::cout << "(m1 == m2): " << std::endl << (m1 == m2) << std::endl;
//    std::cout << "(m1 != m2): " << std::endl << (m1 != m2) << std::endl;
//    std::cout << m1;
    
    // vect * matr
//    Vector<int> v3 (2);
//    std::cout << "(v3 * m1): " << std::endl << (v3 * m1) << std::endl;
    
    //Matrix<int> m2 (3, 4);
    
    //std::cout << "(m1 * m2): " << std::endl << (m1 * m2) << std::endl;
    //std::cout << "(-m1): " << std::endl << (-m1) << std::endl;
    
    // --------- TYPE Proxy ----------
//    Proxy<int> tmp;
//    {
//        Matrix<int> m2 = {{1, 2, 3}, {2, 3, 4}, {3, 4, 5}};
//        Matrix_coords coor_in(1, 1, 2, -1);
//        //std::cout << m2[std::make_tuple(2, 2, 4, 4)] << std::endl;
//        tmp = m2[coor_in];
//        std::cout << tmp(0, 0);
//    }
//        std::cout << tmp;
        
        
//        Proxy<int> tmp;
//        Matrix<int> m2 = {{1, 2, 3}, {2, 3, 4}, {3, 4, 5}};
//        Matrix_coords coor_in_2(2, 2, 5, 5);


   // ----- operator ()
    //std::cout << "m2(1, 1): " << std::endl << *(m2(1, 1)) << std::endl;
    
    

    

    
    
    
//-------------RATIONAL_NUMBERS-----------

    
    
//------------file------init------------
    
//     Vector<Rational_number> new_vector = Inputer<Rational_number>().input_Vector("/Users/volkseriy/Desktop/prac7sem/Task1/task1.cpp/Vector_Rational.txt");
//    std::cout << new_vector << std::endl << std::endl;
//    Matrix<Rational_number> mtx1 = Inputer<Rational_number>().input_Matrix("/Users/volkseriy/Desktop/prac7sem/Task1/task1.cpp/Matrix_Rational.txt");
//
//    Matrix<Rational_number> mtx2 = Inputer<Rational_number>().input_Matrix("/Users/volkseriy/Desktop/prac7sem/Task1/task1.cpp/Matrix_Rational.txt");
//
//    std::cout << mtx1 + mtx2 << std::endl << std::endl;
//    std::cout << mtx1 - mtx2 << std::endl << std::endl;
//    std::cout << mtx1 + mtx2 << std::endl << std::endl;
    
    
//    Matrix<Rational_number> m = Matrix<Rational_number>();
//        //ASSERT_EQ(m.get_size(), 0);
//        m(5, 4) = Rational_number("5/12");
    
//    Matrix<Rational_number> mtx1 = Inputer<Rational_number>().input_Matrix("/Users/volkseriy/Desktop/prac7sem/Task1/tmp/task1.cpp/Tests/Parset_test/Matrix_Rational.txt");
//
//
//    Matrix<Rational_number> mtx2 = {{1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}};
//    std::cout << (mtx1) << "\n";
//    std::cout << (mtx2) << "\n";
//    std::cout << (mtx1 == mtx2) << "\n";
    
    
//    Inputer<Rational_number>().input_Matrix("/Users/volkseriy/Desktop/prac7sem/Task1/tmp/task1.cpp/Tests/Parset_test/Matrix_Rational.txt");
//    Inputer<Rational_number>().input_Matrix("/Users/volkseriy/Desktop/prac7sem/Task1/tmp/task1.cpp/Tests/Parset_test/Matrix_Rational_wrong_1.txt");
    
    
        
    
        Matrix<Rational_number> mtx1 = Inputer<Rational_number>().input_Matrix("./Matrix_Rational.txt");

        Matrix<Rational_number> mtx2 = {{1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}};

        // std::cout << new_vector << std::endl;
        std::cout << mtx1 << std::endl << std::endl;
        std::cout << mtx2 << std::endl << std::endl;

        //ASSERT_EQ(mtx1, mtx2);
        //ASSERT_EQ(mtx1.to_string(), mtx2.to_string());
    
    
    }
    catch(Exeption &e){
        std::cout << e.what() << std::endl;
    }
        
        
    


    return 0;
}
