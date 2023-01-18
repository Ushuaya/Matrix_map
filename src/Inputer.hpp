//
//  Inputer.hpp
//  task1.cpp
//
//  Created by VolkSeriy on 09.10.2022.
//

#ifndef Inputer_hpp
#define Inputer_hpp

#include <stdio.h>
#include <string>
#include <iomanip>
#include <utility>
#include <iostream>
#include <stdexcept>
#include <map>
#include <string>
#include <vector>
#include <fstream>

#include "Vector.hpp"
#include "Matrix.hpp"
#include "Rational_number.hpp"
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
class Inputer
{
private:
public:
    Vector<T> input_Vector(std::string filepath){
        Vector<T> result_vector;
        enum Type_of_vector  { Rational_type, Integer_type };
        Type_of_vector type_v;
        std::string line;
        std::ifstream in(filepath); // окрываем файл для чтения
        uint64_t set_vect_len = 0;
        uint64_t num1;
        uint64_t num2;
        uint64_t num3;
        if (in.is_open()){
            while (getline(in, line)){
                if (line[0] != '#'){
                    if (set_vect_len){
                        if (type_v == Rational_type)
                        {
                            Rational_number r1;
                            std::string delimiter = " ";
                            
                            std::string tmp = "";
                            for(char c:line) if (c != ' ') tmp += c;
                            if (tmp == "") continue;
                            
                            if (line.find("<") == std::string::npos)
                                throw InvalidFileCreationException();
                            else
                                line.replace(line.find("<"), ((std::string)" ").length(), " ");
                            
                            if (line.find(">") == std::string::npos)
                                throw InvalidFileCreationException();
                            else
                                line.replace(line.find(">"), ((std::string)" ").length(), " ");
                            
                            bool flag_slash_expect = false;
                            if (line.find("/") != std::string::npos){
                                flag_slash_expect = true;
                                line.replace(line.find("/"), ((std::string)" ").length(), " ");
                            }
                        
                            
                            size_t pos = 0;
                            std::string token;
                            std::vector<std::string> line_array;
                            while ((pos = line.find(delimiter)) != std::string::npos) {
                                token = line.substr(0, pos);
                                if (token != ""){
                                    line_array.push_back(token);
                                    //std::cout << token << std::endl;
                                }
                                line.erase(0, pos + delimiter.length());
                            }
                            // last part of line
                            if (line != ""){
                                line_array.push_back(line);
                            }
                            if (line_array.size() == 0)
                                continue;
                            
                            if (line_array.size() < 3 && flag_slash_expect == true)
                                throw InvalidFileCreationException();;
                            
                            try{
                                std::string tmp1 = line_array[0];
                                std::size_t pos{};
                                num1 = std::stoi(tmp1, &pos);
                                std::string tmp2 = line_array[1];
                                num2 = std::stoi(tmp2, &pos);
                            }
                            catch (...){
                                throw InvalidVectorSizeException();
                            }
                            
                            if (line_array.size() >= 3){
                                try{
                                    num3 = std::stoi(line_array[2]);
                                    
                                }
                                catch (...){
                                    throw InvalidVectorSizeException();
                                }
                                r1 = Rational_number (line_array[1], line_array[2]);
                            }
                            else{
                                r1 = Rational_number (line_array[1]);
                            }
                            
                            if (num1 > result_vector.get_size() || num1 < 0)
                                throw InvalidVectorSizeException();
                            
                            //std::map <size_t, T> vctr_2;// = (*(result_vector.get_vector()));
                            (*(result_vector.get_vector()))[(size_t)num1] = r1;

                        }
                    }
                    else{
                        std::string delimiter = " ";
                        size_t pos = 0;
                        std::string token;
                        std::vector<std::string> line_array;
                        while ((pos = line.find(delimiter)) != std::string::npos) {
                            token = line.substr(0, pos);
                            line_array.push_back(token);
                            //std::cout << token << std::endl;
                            line.erase(0, pos + delimiter.length());
                        }
                        // last part of line
                        line_array.push_back(line);
                        if (line_array.size() == 0 || line_array[0] == "")
                            continue;
                        if (!set_vect_len){
                            if (line_array[0] == "vector"){
                                if (line_array[1] == "rational"){
                                    type_v = Rational_type;
                                    try{
                                        set_vect_len = stoi(line_array[2]);
                                        result_vector.set_size(set_vect_len);
                                    }
                                    catch (...){
                                        throw InvalidVectorSizeException();
                                    }
                                    //...
                                } else throw InvalidFileInputException();
                            } else throw InvalidFileInputException();
                        }
                        else { //len of vector has been seted
                            
                        }
                    }
                }
            }
        }
        else{
            throw InvalidFileCreationException();
        }
        in.close();     // закрываем файл
        //std::cout << "End of program" << std::endl;
        return result_vector;
    }
    
    Matrix<T> input_Matrix(std::string filepath){
        Matrix<T> result_matrix;
        enum Type_of_vector  { Rational_type, Integer_type };
        Type_of_vector type_v;
        std::string line;
        std::ifstream in(filepath); // окрываем файл для чтения
        uint64_t set_matrix_len = 0;
        uint64_t num1;
        uint64_t num2;
        uint64_t num3;
        uint64_t num4;
        if (in.is_open()){
            while (getline(in, line)){
                if (line[0] != '#'){
                    if (set_matrix_len){
                        if (type_v == Rational_type)
                        {
                            Rational_number r1;
                            std::string delimiter = " ";
                            
                            std::string tmp = "";
                            for(char c:line) if (c != ' ') tmp += c;
                            if (tmp == "") continue;
                            
                            if (line.find("<") == std::string::npos)
                                throw InvalidFileInputException();
                            else
                                line.replace(line.find("<"), ((std::string)" ").length(), " ");
                            
                            if (line.find(">") == std::string::npos)
                                throw InvalidFileInputException();
                            else
                                line.replace(line.find(">"), ((std::string)" ").length(), " ");
                            
                            bool flag_slash_expect = false;
                            if (line.find("/") != std::string::npos){
                                flag_slash_expect = true;
                                line.replace(line.find("/"), ((std::string)" ").length(), " ");
                            }
                            
                            size_t pos = 0;
                            std::string token;
                            std::vector<std::string> line_array;
                            while ((pos = line.find(delimiter)) != std::string::npos) {
                                token = line.substr(0, pos);
                                if (token != ""){
                                    line_array.push_back(token);
                                    //std::cout << token << std::endl;
                                }
                                line.erase(0, pos + delimiter.length());
                            }
                            // last part of line
                            if (line != ""){
                                line_array.push_back(line);
                            }
                            if (line_array.size() == 0)
                                continue;
                            
                            if (line_array.size() < 4 && flag_slash_expect == true)
                                throw InvalidFileInputException();;
                            
                            try{
                                num1 = std::stoi(line_array[0]);
                                num2 = std::stoi(line_array[1]);
                                num3 = std::stoi(line_array[2]);
                            }
                            catch (...){
                                throw InvalidMatrixSizeException();
                            }
                            
                            if (line_array.size() >= 4){
                                try{
                                    num4 = std::stoi(line_array[3]);
                                    
                                }
                                catch (...){
                                    throw InvalidMatrixSizeException();
                                }
                                r1 = Rational_number (line_array[2], line_array[3]);
                            }
                            else{
                                r1 = Rational_number (line_array[2]);
                            }
                            
                            if (num1 > result_matrix.get_n() || num1 < 0)
                                throw InvalidMatrixSizeException();
                            if (num2 > result_matrix.get_m() || num2 < 0)
                                throw InvalidMatrixSizeException();
                            
                            //std::map <size_t, T> vctr_2;// = (*(result_matrix.get_vector()));
                            //(*(result_matrix.get_mtx()))[(size_t)num1] = r1;
                            (*(result_matrix.get_mtx()))[std::make_tuple(num1, num2)] = r1;

                        }
                    }
                    else{
                        std::string delimiter = " ";
                        size_t pos = 0;
                        std::string token;
                        std::vector<std::string> line_array;
                        while ((pos = line.find(delimiter)) != std::string::npos) {
                            token = line.substr(0, pos);
                            line_array.push_back(token);
                            //std::cout << token << std::endl;
                            line.erase(0, pos + delimiter.length());
                        }
                        // last part of line
                        line_array.push_back(line);
                        if (line_array.size() == 0 || line_array[0] == "")
                            continue;
                        if (!set_matrix_len){
                            if (line_array[0] == "matrix"){
                                if (line_array[1] == "rational"){
                                    type_v = Rational_type;
                                    try{
                                        set_matrix_len = stoi(line_array[2]);
                                        result_matrix.set_n(set_matrix_len);
                                        set_matrix_len = stoi(line_array[3]);
                                        result_matrix.set_m(set_matrix_len);
                                        
                                    }
                                    catch (...){
                                        throw InvalidMatrixSizeException();
                                    }
                                    //...
                                } else throw InvalidFileInputException();
                            } else throw InvalidFileInputException();
                        }
                        else { //len of vector has been seted
                            
                        }
                    }
                }
            }
        }
        else{
            throw InvalidFileCreationException();
        }
        in.close();     // закрываем файл
        //std::cout << "End of program" << std::endl;
        return result_matrix;
    }
};

#endif /* Inputer_hpp */
