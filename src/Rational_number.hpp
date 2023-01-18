////
////  Rational_number.hpp
////  task1.cpp
////
////  Created by VolkSeriy on 26.09.2022.
////
//
#ifndef Rational_number_hpp
#define Rational_number_hpp

#include <stdio.h>
#include <string>
#include <cmath>
#include <cfloat>
#include <climits>

#include "Strint.hpp"
#include "Exceptions.hpp"
//
////#include "../exceptions/exceptions.h"
////#include "../StringInt/StringInt.h"
//

/**
       * a normal member taking two arguments and returning an integer value.
       *
       * @see Javadoc_Test()
       * @see ~Javadoc_Test()
       * @see testMeToo()
       * @see publicVar()
       *
       */
class Rational_number {
private:
    StrInt numerator;
    StrInt denominator;
public:

    Rational_number();
    Rational_number(StrInt numen);
    Rational_number(StrInt num, StrInt denom);
    Rational_number(uint16_t numen, uint16_t denom);
    Rational_number(std::string num, std::string denom);
    Rational_number(const std::string& rational);
    StrInt get_numerator() {return this->numerator;};
    StrInt get_denominator() {return this->denominator;};
    Rational_number operator-() {
        return Rational_number(-(this->numerator), this->denominator);
    }
    
    friend std::ostream&  operator << (std::ostream& cout , Rational_number const& ration_number) {
        cout << ration_number.numerator.get_sign() << ration_number.numerator.get_val() << "/" << ration_number.denominator.get_val();
        return cout;
    }
    std::string to_string() {
        return std::string(1, this->numerator.get_sign()) + this->numerator.get_val() + "/" + this->denominator.get_val();
    }

    friend std::istream&  operator >> (std::istream& cin, Rational_number& ration_number) {
        std::string rational_number_string;
        cin >> rational_number_string;
        ration_number = Rational_number(rational_number_string);
        return cin;
    }
    
    friend bool operator < (const Rational_number& left, const Rational_number& right) {
        if (left.numerator.get_sign() == '+' && right.numerator.get_sign() == '-')
            return false;
        if (left.numerator.get_sign() == '-' && right.numerator.get_sign() == '+')
            return true;
        if (left.numerator.get_sign() == '+' && right.numerator.get_sign() == '+')
            return (left.numerator * right.denominator) < (right.numerator * left.denominator) == true ? 1 : 0 ;
        //if (left.numerator.get_sign() == '-' && right.numerator.get_sign() == '-')
        return !((left.numerator * right.denominator) < (right.numerator * left.denominator) == true ? 1 : 0 );
        
        
    }
    
    friend bool operator > (const Rational_number& left, const Rational_number& right) {
        if (right < left)
            return true;
        else return false;
    }
    
    friend bool operator == (const Rational_number& left, const Rational_number& right) {
        return !(left < right) && !(left > right);
    }
    
    friend bool operator != (const Rational_number& left, const Rational_number& right) {
        return !(left==right);
    }
    
    friend bool operator <= (const Rational_number& left, const Rational_number& right) {
        return left < right || left == right;
    }
    
    friend bool operator >= (const Rational_number& left, const Rational_number& right) {
        return left > right || left == right;
    }
    
    friend Rational_number operator + (Rational_number left, Rational_number right);
    friend Rational_number operator - (Rational_number left, Rational_number right);
    friend Rational_number operator * (Rational_number left, Rational_number right);
    friend Rational_number operator / (Rational_number left, Rational_number right);
    
    
    Rational_number& canon_form();
    Rational_number(const long double &rat_num);
    Rational_number(const double &rat_num);
    Rational_number(const float &rat_num);
    Rational_number(const int &rat_num);
    
    Rational_number(const signed& num, const unsigned& dum): numerator(num), denominator(dum) {
        this->canon_form();
    }
    

//

};

Rational_number::Rational_number(): numerator("0"), denominator("1") { }
Rational_number::Rational_number(uint16_t numen, uint16_t denom = 1){
    this->numerator = StrInt(std::to_string(numen));
    this->denominator = StrInt(std::to_string(denom));
    this->canon_form();
}
Rational_number::Rational_number(StrInt numen, StrInt denom) {
    if (denom.get_val() == "0")
        throw DivideByZeroException();
    
    this->denominator = denom;
    this->numerator = numen;
    

    if (numerator.get_sign() == denominator.get_sign()) {
        numerator.set_sign('+');
    }
    if (numerator.get_sign() != denominator.get_sign()) {
        numerator.set_sign('-');
    }
    
    denominator.set_sign('+');
}

Rational_number::Rational_number(StrInt numen) {
    this->denominator.set_val("1");
    this->denominator.set_sign('+');
    this->numerator = numen;
}

Rational_number::Rational_number(std::string numen_s, std::string denom_s) {
    StrInt numen(numen_s);
    StrInt denom(denom_s);
    if (denom.get_val() == "0")
        throw DivideByZeroException();
    
    this->denominator = denom;
    this->numerator = numen;
    

    if (numerator.get_sign() == denominator.get_sign()) {
        numerator.set_sign('+');
    }
    if (numerator.get_sign() != denominator.get_sign()) {
        numerator.set_sign('-');
    }
    
    denominator.set_sign('+');
    
}


Rational_number::Rational_number(const std::string& rational_number) {
    //Rational_number tmp_result;
    std::string tmp_rational_number = rational_number;
    if (rational_number == ""){
        throw "No string";
    }
    this->denominator.set_sign('+');
    this->numerator.set_sign('+');
    if (tmp_rational_number[0] == '+'){
        //this->numerator.set_sign('+');
        tmp_rational_number.erase(0, 1);
    }
    if (tmp_rational_number[0] == '-'){
        this->numerator.set_sign('-');
        tmp_rational_number.erase(0, 1);
    }
    
    
    // check
    
    auto dot_pos = tmp_rational_number.find('.');
    if (dot_pos == std::string::npos) {
        
        auto dot_pos = tmp_rational_number.find('/');
        if (dot_pos == std::string::npos) {
            this->denominator.set_val("1");
            this->numerator.set_val(tmp_rational_number);
            this->canon_form();
            
        } else {
            auto fractional_part = tmp_rational_number.substr(dot_pos);
            fractional_part.erase(0, 1);
            //std::cout << fractional_part << " dsskd\n";
            auto &tmp__ = tmp_rational_number;
//            for (size_t k = tmp__.find('a'); k != tmp__.npos;  k = tmp__.find('a', k )){
//                tmp__.erase(k, 1);
//            }
            tmp_rational_number.erase(dot_pos, fractional_part.size()+1);
            this->numerator.set_val(tmp_rational_number);
            this->denominator.set_val(fractional_part);
            //std::cout << tmp_rational_number << " dsskd\n";
//            for (int i = 0; i < fractional_part; i++) {
//                this->denominator.set_val(this->denominator.get_val() + "0");
            this->canon_form();
            }
        }
     else {
        
        auto fractional_part = tmp_rational_number.substr(dot_pos).size() - 1;
        
        auto &tmp__ = tmp_rational_number;
        for (size_t k = tmp__.find('a'); k != tmp__.npos;  k = tmp__.find('a', k )){
            tmp__.erase(k, 1);
        }
        tmp_rational_number.erase(dot_pos, 1);
        this->numerator.set_val(tmp_rational_number);
        this->denominator.set_val("1");
        for (int i = 0; i < fractional_part; i++) {
            this->denominator.set_val(this->denominator.get_val() + "0");
        }
        this->canon_form();
    }
}

Rational_number& Rational_number::canon_form() {
    StrInt GGCCDD (StrInt::gcd(numerator.get_val(), denominator.get_val()));
    this->numerator = this->numerator/GGCCDD;
    this->denominator = this->denominator/GGCCDD;
    if (this->denominator.get_sign() == '-'){
        if (this->numerator.get_sign() == '-'){
            this->numerator.set_sign('+');
            this->denominator.set_sign('+');
        }
        else{
            this->numerator.set_sign('-');
            this->denominator.set_sign('+');
        }
    }
    return *this;
}

Rational_number operator + (Rational_number left, Rational_number right)
{
    //StrInt GGCCDD (StrInt::gcd(left.denominator.get_val(), right.denominator.get_val()));
    StrInt tmp1(left.denominator.get_val());
    StrInt tmp2(right.denominator.get_val());
    left.numerator.set_val((left.numerator * tmp2).get_val());
    left.denominator.set_val((left.denominator * tmp2).get_val());
    right.numerator.set_val((right.numerator * tmp1).get_val());
    right.denominator.set_val((right.denominator * tmp1).get_val());
    Rational_number tmp(left.numerator + right.numerator, left.denominator);
    tmp.canon_form();
    return tmp;
}

Rational_number operator - (Rational_number left, Rational_number right)
{
    //StrInt GGCCDD (StrInt::gcd(left.denominator.get_val(), right.denominator.get_val()));
    StrInt tmp1(left.denominator.get_val());
    StrInt tmp2(right.denominator.get_val());
    left.numerator.set_val((left.numerator * tmp2).get_val());
    left.denominator.set_val((left.denominator * tmp2).get_val());
    right.numerator.set_val((right.numerator * tmp1).get_val());
    right.denominator.set_val((right.denominator * tmp1).get_val());
    Rational_number tmp(left.numerator - right.numerator, left.denominator);
    tmp.canon_form();
    return tmp;
}

Rational_number operator * (Rational_number left, Rational_number right)
{
    Rational_number tmp1;
    StrInt tmp_strint = (left.numerator * right.numerator);
    tmp1.numerator.set_val(tmp_strint.get_val());
    tmp1.numerator.set_sign(tmp_strint.get_sign());
    tmp1.denominator.set_val((left.denominator * right.denominator).get_val());
    tmp1.canon_form();
    return tmp1;
}

Rational_number operator / (Rational_number left, Rational_number right)
{
    Rational_number tmp1 (StrInt(right.numerator.get_sign(), (std::string)right.denominator.get_val()),
                          StrInt('+', right.numerator.get_val()));
    StrInt tmp_strint = (left.numerator * right.numerator);
    tmp1.numerator.set_val(tmp_strint.get_val());
    tmp1.numerator.set_sign(tmp_strint.get_sign());
    tmp1.denominator.set_val((left.denominator * tmp1.denominator).get_val());
    tmp1.canon_form();
    return tmp1;
}


Rational_number::Rational_number(const long double &rat_num) {
    Rational_number tmp = Rational_number(std::to_string(rat_num));
    tmp.numerator.clean_zeros();
    tmp.denominator.clean_zeros();
    this->numerator = tmp.numerator;
    this->denominator = tmp.denominator;
    
}
Rational_number::Rational_number(const double &rat_num) {
    Rational_number tmp = Rational_number(std::to_string(rat_num));
    tmp.numerator.clean_zeros();
    tmp.denominator.clean_zeros();
    this->numerator = tmp.numerator;
    this->denominator = tmp.denominator;
}

Rational_number::Rational_number(const float &rat_num) {
    Rational_number tmp = Rational_number(std::to_string(rat_num));
    tmp.numerator.clean_zeros();
    tmp.denominator.clean_zeros();
    this->numerator = tmp.numerator;
    this->denominator = tmp.denominator;
}

Rational_number::Rational_number(const int &rat_num) {
    Rational_number tmp = Rational_number(std::to_string(rat_num));
    tmp.numerator.clean_zeros();
    tmp.denominator.clean_zeros();
    this->numerator = tmp.numerator;
    this->denominator = tmp.denominator;
}



//Rational_number operator-(Rational_number lhs, const Rational_number& rhs);
//Rational_number operator*(Rational_number lhs, const Rational_number& rhs);
//
//
//Rational_number operator/(Rational_number lhs, const Rational_number& rhs);



#endif /* Rational_number_hpp */
