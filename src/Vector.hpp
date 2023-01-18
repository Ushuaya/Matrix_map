//
//  Vector.hpp
//  task1.cpp
//
//  Created by VolkSeriy on 25.09.2022.
//

#ifndef Vector_hpp
#define Vector_hpp

#include <stdio.h>
#include <map>
#include <string>
#include <iostream>

#include "Matrix.hpp"
#include "Exceptions.hpp"
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
class Vector{
    private:
        double epsilon = 0.1;
        size_t vector_size;
        double **mtrx;
        std::map <size_t, T> vctr;
        int matx_n;
        int matx_m;

    public:
        Vector();
        Vector(int size);
        Vector(int size, int no_input);
        uint64_t get_size(){return this->vector_size;}
        std::map<size_t, T>* get_vector(){return &vctr;}
        void set_size(uint64_t size_f){this->vector_size = size_f;}
        template <typename U>
        friend bool operator == (Vector<U>& V_F_1, Vector<U>& V_F_2);
        template <typename U>
        friend bool operator != (Vector<U>& V_F_1, Vector<U>& V_F_2);
        template <typename U>
        friend std::ostream& operator << (std::ostream &out, Vector<U> x);
        template <typename U>
        friend Vector<U> operator + (Vector<U>& V_F_1, Vector<U>& V_F_2);
        template <typename U>
        friend Vector<U> operator - (Vector<U>& V_F_1, Vector<U>& V_F_2);
        template <typename U>
        friend Vector<U> operator * (Vector<U>& V_F, U scalar_f);
        template <typename U>
        friend Vector<U> operator * (Vector<U>& V_F, Matrix<U>& M_F);
        
    std::string to_string (){
        std::string result;
        for(auto it = this->vctr.begin(); it != this->vctr.end(); ++it)
        {
            result += this->vctr[it->first].to_string();
            result += " ";
        }
        return result;
    }
        

        // Vector Vector[i];
        ~Vector();
        
        T* operator[](int i_f)
        {
            
            return &(this->vctr[i_f]);
        }

        
        
        
        /*
         static Vector identity( int n );
         Vector( int n, int m);
         Vector( double*, int m );
         Vector(int n , double*);
         Vector(double a);
         Vector( char*);
         Vector operator -() const;
         Vector operator [](int idx) const;
         
         
         friend Vector operator * (Vector &V_F_1, Vector &V_F_2);
         friend bool operator != (Vector &V_F_1, Vector &V_F_2);
         friend Vector operator | (Vector &V_F_1, Vector &V_F_2);
         friend Vector operator / (Vector &V_F_1, Vector &V_F_2);
         */
        
    };



template <typename T>
Vector<T>::Vector(){
    this->vector_size = 0;
}

template <typename T>
Vector<T>::Vector(int size){
    std::cout << "new vector: " << std::endl;
    for (int i = 0; i < size; i++)
    {
        int tmp;
        std::cout << " next: ";
        std::cin >> tmp;
        vctr[i] = tmp;
    }
    std::cout << std::endl;
}

template <typename T>
Vector<T>::Vector(int size, int input){}

template <typename T>
Vector<T>::~Vector()
{
    std::cout << "DESTRUCTOR\n";
}

template <typename T>
Vector<T> operator * (Vector<T>& V_F_1, Matrix<T>& M_F)
{
    
    if(V_F_1.vctr.size() == M_F.get_n())
    {
        Vector<T> tmp (0, 0);
        //std::cout << M_F.get_m() << "\n";
        for (int j = 0; j < M_F.get_m(); j++)
        {
            int summ = 0;
            for (int i = 0; i < M_F.get_n(); i++)
            {
                summ += V_F_1.vctr[i] * M_F.get_mtx()[std::make_tuple(i, j)];
            }
            tmp.vctr[j] = summ;
        }
        return tmp;
    }
    else
    {
        throw MultiplyErrorException();
    }
}

template <typename T>
bool operator == (Vector<T>& V_F_1, Vector<T>& V_F_2)
{
    if(V_F_1.vctr.size() == V_F_2.vctr.size())
    {
        for(auto it = V_F_1.vctr.begin(); it != V_F_1.vctr.end(); ++it)
        {
            if (V_F_1.vctr[it->first] != V_F_2.vctr[it->first])
                return false;
        }
        return true;

    }
    else
        return false;
}

template <typename T>
bool operator != (Vector<T>& V_F_1, Vector<T>& V_F_2)
{
    if(V_F_1.vctr.size() == V_F_2.vctr.size())
    {
        for(auto it = V_F_1.vctr.begin(); it != V_F_1.vctr.end(); ++it)
        {
            if (V_F_1.vctr[it->first] != V_F_2.vctr[it->first])
                return true;
        }
        return false;

    }
    else
        return true;
}

template <typename T>
Vector<T> operator + (Vector<T>& V_F_1, Vector<T>& V_F_2)
{
    
    if(V_F_1.vctr.size() == V_F_2.vctr.size())
    {
        Vector<T> tmp = V_F_1;
        for(auto it = V_F_1.vctr.begin(); it != V_F_1.vctr.end(); ++it)
        {
            tmp.vctr[it->first] = V_F_1.vctr[it->first] + V_F_2.vctr[it->first];
        }
        return tmp;
    }
    else
    {
        throw PlusErrorException();
    }
}

template <typename T>
Vector<T> operator - (Vector<T>& V_F_1, Vector<T>& V_F_2)
{
    
    if(V_F_1.vctr.size() == V_F_2.vctr.size())
    {
        Vector<T> tmp = V_F_1;
        for(auto it = V_F_1.vctr.begin(); it != V_F_1.vctr.end(); ++it)
        {
            tmp.vctr[it->first] = V_F_1.vctr[it->first] - V_F_2.vctr[it->first];
        }
        return tmp;
    }
    else
    {
        throw MinusErrorException();
    }
}

//template <typename T>
//Matrix<T> VCONV (Matrix<T>& M_F, std::tuple<size_t, size_t> c1, std::tuple<size_t, size_t> c2){
//    return;
//};

template <typename T>
std::ostream& operator<<(std::ostream &out, Vector<T> V_F_1){
    for(auto it = V_F_1.vctr.begin(); it != V_F_1.vctr.end(); ++it)
    {
        out << V_F_1.vctr[it->first] << " ";
    }
    out << std::endl;
    return out;
}

//13)
template <typename T>
Vector<T> operator *(Vector<T>& V_F, T scalar_f)
{
    
    Vector<T> tmp = V_F;
    for(auto it = V_F.vctr.begin(); it != V_F.vctr.end(); ++it)
    {
        tmp.vctr[it->first] = V_F.vctr[it->first] * scalar_f;
    }
    return tmp;
}






#endif /* Vector_hpp */
