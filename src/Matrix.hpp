//
//  Matrix.hpp
//  task1.cpp
//
//  Created by VolkSeriy on 25.09.2022.
//

#ifndef Matrix_hpp
#define Matrix_hpp

#include <stdio.h>
#include <map>
#include <string>
#include <iostream>

#include "Proxy.hpp"
#include "Matrix_coords.hpp"
#include "Rational_number.hpp"
#include "Exceptions.hpp"



template <typename T>
class Proxy;

/**
       * a normal member taking two arguments and returning an integer value.
       *  a an integer argument.
       *  s a constant character pointer.
       * @see Javadoc_Test()
       * @see ~Javadoc_Test()
       * @see testMeToo()
       * @see publicVar()
       *  The test results
       */
template <typename T>
class Matrix
    {
    private:
        double epsilon = 0.1;
        std::map <std::tuple<size_t, size_t>, T> vctr;
        uint64_t matx_n;
        uint64_t matx_m;

    public:
        const std::shared_ptr<bool> ptr = std::make_shared<bool>();
        
        Matrix(): matx_n(10), matx_m(10){};
        Matrix(int height, int width);
        template <typename U>
        friend bool operator == (Matrix<U>& M_F_1, Matrix<U>& M_F_2);
        template <typename U>
        friend bool operator != (Matrix<U>& M_F_1, Matrix<U>& M_F_2);
        template <typename U>
        friend std::ostream& operator << (std::ostream &out, Matrix<U> x);
        template <typename U>
        friend Matrix<U> operator + (Matrix<U>& M_F_1, Matrix<U>& M_F_2);
        template <typename U>
        friend Matrix<U> operator - (Matrix<U>& M_F_1, Matrix<U>& M_F_2);
        template <typename U>
        friend Matrix<U> operator * (Matrix<U>& M_F, U scalar_f);
        template <typename U>
        friend Matrix<U> operator * (Matrix<U>& M_F_1, Matrix<U>& M_F_2);
//        template <typename U>
//        friend Matrix<U> operator * (Matrix<U>& M_F_1, Matrix<U>& M_F_2);
//        template <typename U>
//        friend  Matrix<U> VCONV (Matrix<U>& M_F, std::tuple<size_t, size_t>, std::tuple<size_t, size_t>);
        Proxy<T> operator[](Matrix_coords coords_out) const;
        
        Matrix(const Matrix<T> & ref_Point);
        Matrix<T> & operator = (const Matrix<T> & other);
        Matrix(Matrix<T> && obj) noexcept;
        Matrix<T> & operator = (Matrix<T>&& );
        
        
        
        uint64_t get_n() {return matx_n;}
        uint64_t get_m() {return matx_m;}
        void set_n (int set){matx_n=set;}
        void set_m (int set){matx_m=set;}
        std::map <std::tuple<size_t, size_t>, T>* get_mtx (){return &vctr;}
        
        Matrix operator -() ;
        
        // ------ method to erase values < epsilon
        void clean_mtx(){
            for(uint64_t i = 0; i < this->get_n(); i++)
                for(uint64_t j = 0; j < this->get_m(); j++)
                    if (!(vctr.find(std::make_tuple(i, j)) == vctr.end()))
                        if (this->vctr[std::make_tuple(i, j)] < T(epsilon))
                            this->vctr.erase(std::make_tuple(i, j));}

        ~Matrix();
        
        
         T& operator()(uint64_t i, uint64_t j);
        Matrix(std::initializer_list<std::initializer_list<T>> lst);
         //T& operator()(int, int);
        
        size_t get_size() const {
                return this->vctr.size();
            }
        
        std::string to_string() {
            std::string result;
            for (int i = 0; i < this->get_n(); i++)
            {
                for (int j = 0; j < this->get_m(); j++)
                {
                    result += this->vctr[std::make_tuple(i, j)].to_string();
                    result += " , ";
                }
                result += "\n";
            }
            //M_F_1.clean_mtx();
            return result;
        }

    };


template <typename T>
Matrix<T>::Matrix(std::initializer_list<std::initializer_list<T>> lst){
     uint64_t i = 0, j = 0;
    this->set_n(lst.size());
    this->set_m(lst.size() ? lst.begin()->size() : 0);
     for (const auto& l : lst)
     {
        for (const auto& v : l)
        {
           this->vctr[std::make_tuple(i, j)] = T(v);
           ++j;
        }
        j = 0;
        ++i;
     }
    this->clean_mtx();
  }


template <typename T>
T& Matrix<T>::operator()(uint64_t i, uint64_t j) {
        this->clean_mtx();
    
        if ((i >= this->get_n() || j >= this->get_m())) {
            throw OutOfRangeExseption();
        }
        if (this->vctr.find(std::make_tuple(i, j)) == this->vctr.end()) {
            this->vctr[std::make_tuple(i, j)] = T(0);
        }
        return vctr[std::make_tuple(i, j)];
    }




template <typename T>
Matrix<T> Matrix<T>::operator -()
{
    Matrix<T> tmp;
    tmp.set_m(get_m());
    tmp.set_n(get_n());
    for(size_t i = 0; i < matx_n; i++)
        for(size_t j = 0; j < matx_m; j++){
            tmp.vctr[std::make_tuple(i, j)] = -(vctr[std::make_tuple(i, j)]);
        }
    this->clean_mtx();
    return tmp;
}



template <typename T>
Matrix<T> operator * (Matrix<T>& M_F_1, Matrix<T>& M_F_2)
{
    
    if(M_F_1.matx_m == M_F_2.matx_n){
        Matrix<T> tmp;
        tmp.set_n(M_F_1.get_n());
        tmp.set_m(M_F_2.get_m());
        uint64_t i,j,k;
        for(i = 0; i < M_F_1.get_n(); i++)
            for(j = 0; j < M_F_2.get_m(); j++){
                tmp.vctr[std::make_tuple(i, j)] = T(0);
                for(k = 0; k < M_F_1.matx_m; k++)
                    tmp.vctr[std::make_tuple(i, j)] += (M_F_1.vctr[std::make_tuple(i, k)] * M_F_2.vctr[std::make_tuple(k, j)]);
            }
        M_F_1.clean_mtx();
        M_F_2.clean_mtx();
        return tmp;
    }
    else{
        throw MultiplyErrorException();
    }
}

template <typename T>
Matrix<T> & Matrix<T>::operator = (Matrix<T>&& other)
{
  // 1. Проверка, нет ли присваивания самому себе
  if (&other == this)
    return *this;

    matx_n = other.matx_n;
    matx_m = other.matx_m;
    epsilon = other.epsilon;
    for(auto it = other.vctr.begin(); it != other.vctr.end(); ++it)
    {
        vctr[it->first] = other.vctr[it->first];
    }
    this->clean_mtx();
  return *this;
}


template <typename T>
Matrix<T>::Matrix(Matrix<T> && other) noexcept
{
  // 1. Перенаправить A на obj.A и изменить count
    matx_n = other.matx_n;
    matx_m = other.matx_m;
    epsilon = other.epsilon;
    for(auto it = other.vctr.begin(); it != other.vctr.end(); ++it)
    {
        vctr[it->first] = other.vctr[it->first];
    }
    this->clean_mtx();
}


//operator =
template <typename T>
Matrix<T> & Matrix<T>::operator = (const Matrix<T> & other)
{
    if (this != &other) // защита от неправильного самоприсваивания
    {
        matx_n = other.matx_n;
        matx_m = other.matx_m;
        epsilon = other.epsilon;
        for(auto it = other.vctr.begin(); it != other.vctr.end(); ++it)
        {
            vctr[it->first] = other.vctr[it->first];
        }
    }
    this->clean_mtx();
    
}

// coping constructor
template <typename T>
Matrix<T>::Matrix(const Matrix<T> & right_arg)
{
    // копирование данных из одного объекта в другой
    matx_n = right_arg.matx_n;
    matx_m = right_arg.matx_m;
    epsilon = right_arg.epsilon;
    for(auto it = right_arg.vctr.begin(); it != right_arg.vctr.end(); ++it)
    {
        vctr[it->first] = right_arg.vctr.at(it->first);
    }
    this->clean_mtx();
    
}

//template <typename T>
//T* Matrix<T>::operator()(int i_f, int j_f)
//{
//    return &(this->vctr[std::make_tuple(i_f, j_f)]);
//}


template <typename T>
Matrix<T>::Matrix(int height, int width){
    this->matx_n = height;
    this->matx_m = width;
    std::cout << "new Matrix: " << std::endl;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int tmp;
            std::cout << " (" << i << ", " << j << "): ";
            std::cin >> tmp;
            vctr[std::make_tuple(i, j)] = tmp;
        }
    }
    std::cout << std::endl;
}

template <typename T>
Matrix<T>::~Matrix()
{
    std::cout << "DESTRUCTOR Matrix\n";
}

template <typename T>
bool operator == (Matrix<T>& M_F_1, Matrix<T>& M_F_2)
{
    if(M_F_1.matx_n == M_F_2.matx_n && M_F_1.matx_m == M_F_2.matx_m)
    {
        
        for (int i = 0; i < M_F_1.matx_n; i++)
        {
            for (int j = 0; j < M_F_1.matx_m; j++)
            {
                if( M_F_1.vctr[std::make_tuple(i, j)] != M_F_2.vctr[std::make_tuple(i, j)] ){
                    M_F_1.clean_mtx();
                    M_F_2.clean_mtx();
                    return false;
                }
            }
        }
        M_F_1.clean_mtx();
        M_F_2.clean_mtx();
        return true;
    }
    else
        M_F_1.clean_mtx();
        M_F_2.clean_mtx();
        return false;
}

template <typename T>
bool operator != (Matrix<T>& M_F_1, Matrix<T>& M_F_2)
{
    if(M_F_1.vctr.size() == M_F_2.vctr.size())
    {
        for (int i = 0; i < M_F_1.matx_n; i++)
        {
            for (int j = 0; j < M_F_1.matx_m; j++)
            {
                if( M_F_1.vctr[std::make_tuple(i, j)] != M_F_2.vctr[std::make_tuple(i, j)] ){
                    M_F_1.clean_mtx();
                    M_F_2.clean_mtx();
                    return true;
                }
            }
        }
        M_F_1.clean_mtx();
        M_F_2.clean_mtx();
        return false;

    }
    else
        M_F_1.clean_mtx();
        M_F_2.clean_mtx();
        return true;
}



template <typename T>
Matrix<T> operator + (Matrix<T>& M_F_1, Matrix<T>& M_F_2)
{
    
    if(M_F_1.matx_n == M_F_2.matx_n && M_F_1.matx_m == M_F_2.matx_m)
    {
        Matrix<T> tmp = M_F_1;
        for (int i = 0; i < M_F_1.matx_n; i++)
        {
            for (int j = 0; j < M_F_1.matx_m; j++)
            {
                tmp.vctr[std::make_tuple(i, j)] = M_F_1.vctr[std::make_tuple(i, j)] + M_F_2.vctr[std::make_tuple(i, j)];
            }
        }
        M_F_1.clean_mtx();
        M_F_2.clean_mtx();
        tmp.clean_mtx();
        return tmp;
    }
    else
    {
        throw MultiplyErrorException();
    }
}

template <typename T>
Matrix<T> operator - (Matrix<T>& M_F_1, Matrix<T>& M_F_2)
{
    
    if(M_F_1.matx_n == M_F_2.matx_n && M_F_1.matx_m == M_F_2.matx_m)
    {
        Matrix<T> tmp = M_F_1;
        for (int i = 0; i < M_F_1.matx_n; i++)
        {
            for (int j = 0; j < M_F_1.matx_m; j++)
            {
                tmp.vctr[std::make_tuple(i, j)] = M_F_1.vctr[std::make_tuple(i, j)] - M_F_2.vctr[std::make_tuple(i, j)];
            }
        }
        M_F_1.clean_mtx();
        M_F_2.clean_mtx();
        tmp.clean_mtx();
        return tmp;
    }
    else
    {
        throw MultiplyErrorException();
    }
}



template <typename T>
std::ostream& operator<<(std::ostream &out, Matrix<T> M_F_1){

    for (int i = 0; i < M_F_1.matx_n; i++)
    {
        for (int j = 0; j < M_F_1.matx_m; j++)
        {
            out << M_F_1.vctr[std::make_tuple(i, j)] << " ";
        }
        out << std::endl;
    }
    //M_F_1.clean_mtx();
    return out;
}

//13)
template <typename T>
Matrix<T> operator *(Matrix<T>& M_F, T scalar_f)
{
    
    Matrix<T> tmp = M_F;
    for(auto it = M_F.vctr.begin(); it != M_F.vctr.end(); ++it)
    {
        tmp.vctr[it->first] = M_F.vctr[it->first] * scalar_f;
    }
    M_F.clean_mtx();
    return tmp;
}



template <typename T>
Proxy<T> Matrix<T>::operator[](Matrix_coords coords_out) const
{
    std::tuple<int, int, int, int> coor = std::make_tuple(coords_out.get_c1(), coords_out.get_r1(), coords_out.get_c2(), coords_out.get_r2());
    return Proxy<T>(this, coor);
}




#include "Matrix.cpp"
#endif /* Matrix_hpp */



