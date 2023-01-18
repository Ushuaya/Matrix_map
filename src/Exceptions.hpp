//
//  Exceptions.hpp
//  task1.cpp
//
//  Created by VolkSeriy on 13.10.2022.
//

#ifndef Exceptions_hpp
#define Exceptions_hpp

#include <cstdio>

#include <iostream>

class Exeption : public std::exception {
private:
    std::string error;
    int line;
    int sym;
    std::string func;
    
public:
    Exeption();
    Exeption(int ERR_CODE);
    Exeption(std::string ferror, int line, int sym, std::string ffunc);
    std::string GetName() const {return error;}
    Exeption(const Exeption& source);
    std::string what () {
        return this->error;
    }
    void set_error(std::string out_error){
        this->error = out_error;
    }
    ~Exeption();
};

Exeption::Exeption(){
    this->error = "Undefined error";
}

Exeption::Exeption(std::string ferror, int fline = 0, int fsym = 0, std::string ffunc = ""){
    this->error = ferror;
    this->line = fline;
    this->sym = fsym;
    this->func = ffunc;
}


Exeption::Exeption(const Exeption& source){
    if (source.GetName() != ""){
        this->error = source.error;
    }
    else
        this->error = "Undefined error";
    
    this->line = source.line;
    this->sym = source.sym;
    
    if (source.func != ""){
        this->func = source.func;
    }
}



Exeption::~Exeption(){
}


class DivideByZeroException : public Exeption {
public:
    DivideByZeroException(){
        this->set_error("Devidion by zero is not allowed");
    }
};

class InvalidFileCreationException : public Exeption {
public:
    InvalidFileCreationException(){
        this->set_error("Error when trying to open file");
    }
};

class InvalidVectorSizeException : public Exeption {
public:
    InvalidVectorSizeException(){
        this->set_error("Error when trying to set the vector size");
    }
};

class InvalidFileInputException : public Exeption {
public:
    InvalidFileInputException(){
        this->set_error("Error when trying to read file");
    }
};

class InvalidMatrixSizeException : public Exeption {
public:
    InvalidMatrixSizeException(){
        this->set_error("Error when trying to set the matrix size");
    }
};

class MultiplyErrorException : public Exeption {
public:
    MultiplyErrorException(){
        this->set_error("Matrix are not suitable for * operation ");
    }
};

class PlusErrorException : public Exeption {
public:
    PlusErrorException(){
        this->set_error("Matrix are not suitable for + operation ");
    }
};

class MinusErrorException : public Exeption {
public:
    MinusErrorException(){
        this->set_error("Matrix are not suitable for - operation ");
    }
};

class OutOfRangeExseption : public Exeption {
public:
    OutOfRangeExseption(){
        this->set_error("Index out of Matrix size");
    }
};

class ExpiredElementException : public Exeption {
public:
    ExpiredElementException(){
        this->set_error("Element on which this pointer refers is expired");
    }
};

class ProxyCoordsException : public Exeption {
public:
    ProxyCoordsException(){
        this->set_error("Invalid arguments for matrix coords");
    }
};

#endif /* Exceptions_hpp */
