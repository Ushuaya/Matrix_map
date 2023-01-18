//
//  Matrix_coords.hpp
//  task1.cpp
//
//  Created by VolkSeriy on 25.09.2022.
//

#ifndef Matrix_coords_hpp
#define Matrix_coords_hpp

#include <stdio.h>
#include <stdio.h>
#include <map>
#include <string>
#include <iostream>
#include "Matrix.hpp"


template <typename T>
class Matrix;


class Matrix_coords
{
private:
    long long int c1;
    long long int r1;
    long long int c2;
    long long int r2;
public:
    long long int get_c1() {return c1;}
    long long int get_r1() {return r1;}
    long long int get_c2() {return c2;}
    long long int get_r2() {return r2;}
    
    Matrix_coords(long long int, long long int, long long int, long long int);
};

Matrix_coords::Matrix_coords(long long int c1_out, long long int r1_out, long long int c2_out, long long int r2_out){
    this->c1 = c1_out;
    this->r1 = r1_out;
    this->c2 = c2_out;
    this->r2 = r2_out;
}


#endif /* Matrix_coords_hpp */
