//
//  Proxy.hpp
//  task1.cpp
//
//  Created by VolkSeriy on 18.10.2022.
//

#ifndef Proxy_hpp
#define Proxy_hpp

#include <cstdio>
#include <map>
#include <string>
#include <iostream>

#include "Matrix.hpp"
#include "Exceptions.hpp"


template <typename T>
class Matrix;


template <typename T>
class Proxy
    {
    private:
//        std::map<std::tuple<size_t, size_t>, T>::iterator self_iter;
        long long int c1;
        long long int r1;
        long long int c2;
        long long int r2;
        Matrix<T> * m_p;
        
    public:
        long long int offset_x;
        long long int offset_y;
        
        std::weak_ptr<bool> parnt_ptr;
        Proxy(): c1(-1), c2(-1), r1(-1), r2(-1){}
        Proxy(const Matrix<T> *, std::tuple<int, int, int, int>);
        template <typename U>
        friend std::ostream& operator << (std::ostream &out, Proxy<U> x);
        bool parentExist(){
            return !(parnt_ptr.expired());
        }
        T& operator()(size_t, size_t);
    };

template <typename T>
std::ostream& operator << (std::ostream &out, Proxy<T> M_F){
    
    if (M_F.parentExist()){
    if ((M_F.c1 > M_F.c2 && M_F.c2 != -1) || (M_F.r1 > M_F.r2 && M_F.r2 != -1)) {
        throw "Invalid arguments for matrix coords";
    } else {
        if (M_F.c1 < -1 || M_F.r1 > (long long int)(*(M_F.m_p)).get_n() - 1 || M_F.c2 < -1 || M_F.r2 > (long long int)(*(M_F.m_p)).get_m() - 1)
        {
            std::cout << M_F.c1 << M_F.r1 << (*(M_F.m_p)).get_n() - 1 << M_F.c2 << M_F.r2 << (*(M_F.m_p)).get_m() - 1 << std::endl;
            throw "Invalid arguments for matrix coords";
        }
        else
        {
            
            int i, j;
            for (M_F.c1 == -1 ?  i = 0 :  i = M_F.c1; M_F.c2 == -1 ? i < (*(M_F.m_p)).get_n() : i <= M_F.c2 ; i++)
            {
                for (M_F.r1 == -1 ? j = 0 : j = M_F.r1; M_F.r2 == -1 ? j < (*(M_F.m_p)).get_m() : j <= M_F.r2; j++)
                {
                    out << (*(*(M_F.m_p)).get_mtx())[std::make_tuple(i, j)] << " ";
                }
                out << std::endl;
            }
            return out;
        }
    }
    }
    else{ // parent was deleted
        throw ExpiredElementException();
    }
}



template <typename T>
 Proxy<T>::Proxy(const Matrix<T> * matr, std::tuple<int, int, int, int> coor_f){
    //int max_right_offset = std::get<1>(coor_f) - std::get<3>(coor_f);
    //int max_down_offset = std::get<0>(coor_f) - std::get<2>(coor_f);
     this->parnt_ptr = matr->ptr;
    this->c1 = std::get<0>(coor_f);
    this->r1 = std::get<1>(coor_f);
    this->c2 = std::get<2>(coor_f);
    this->r2 = std::get<3>(coor_f);
     if (this->c1 != -1){
         this->offset_y = this->c1;
     }
     else{
         this->offset_y = 0;
     }
     
     if (this->r1 != -1){
         this->offset_x = this->r1;
     }
     else{
         this->offset_x = 0;
     }
    //std::cout << "TUT\n" << this->c1 << "\n" << this->r1 << "\n" << (*(const_cast <Matrix<T> *> (matr))).get_n() - 1 << "\n" << this->c2 << "\n" << this->r2 << "\n" << (*(const_cast <Matrix<T> *> (matr))).get_m() - 1 << std::endl;
//     std::cout << (this->c1 > this->c2 && this->c2 != -1) << "\n";
//     std::cout << (this->r1 > this->r2 && this->r2 != -1) << "\n";
//     std::cout << (this->c2 < -1) << "\n";
//     std::cout << (this->c2 > (long long int)((*(const_cast <Matrix<T> *> (matr))).get_n() - 1)) << "\n";
//     std::cout << (this->c2 < -1) << "\n";
//     std::cout << (this->r2 > (long long int)((*(const_cast <Matrix<T> *> (matr))).get_m() - 1)) <<"\n";
//
//     std::cout << this->r2 <<"\n";
//     std::cout << (*(const_cast <Matrix<T> *> (matr))).get_m() - 1 <<"\n";
    if ((this->c1 > this->c2 && this->c2 != -1) || (this->r1 > this->r2 && this->r2 != -1) || (this->c1 < -1) || (this->c2 > (long long int)(*(const_cast <Matrix<T> *> (matr))).get_n() - 1) || (this->c2 < -1) || (this->r2 > (long long int)((*(const_cast <Matrix<T> *> (matr))).get_m() - 1)))
    {
     throw ProxyCoordsException();
    }
     
    m_p = const_cast <Matrix<T> *> (matr);
    //auto iter = (*matr).vctr.begin();
    //return this;
}

template <typename T>
T& Proxy<T>::operator()(size_t i, size_t j) {
    if (this->parentExist()){
            return this->m_p->operator()(i + this->offset_y, j + this->offset_x);
    }
    else{ // parent was deleted
        throw ExpiredElementException();
    }
}



#endif /* Proxy_hpp */
