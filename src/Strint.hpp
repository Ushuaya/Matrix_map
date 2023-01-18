//
//  Strint.hpp
//  task1.cpp
//
//  Created by VolkSeriy on 26.09.2022.
//

#ifndef Strint_hpp
#define Strint_hpp

#include <stdio.h>
#include <string>
#include <map>
#include <iostream>
#include <cfloat>
#include <climits>
#include <algorithm>
#include <string_view>

//#include "../exceptions/exceptions.h"
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
class StrInt {
private:
    char sign;
    std::string val;
    
public:
    std::string get_val() const {return val;}
    char get_sign() const {return sign;}
    void set_val(std::string val_f)  {val = val_f;}
    void set_sign(char sign_f) {this->sign = sign_f;}
    enum cmpr { smaller, equal, bigger};
    static std::string plus_str(const std::string& left, const std::string& right);
    static std::string minus_str(std::string left,  std::string right);
    static std::string multiply_str( std::string left,  std::string right);
    static std::tuple <std::string, std::string> delete_str( std::string left,  std::string right);
    void clean_zeros(){
        while(this->val.length() > 1 && this->val[0] == '0')
            this->val.erase(this->val.begin());
    }

    friend StrInt::cmpr  operator <(const std::string& left, const std::string& right);
    StrInt();
    StrInt(const std::string& number);
    StrInt(char sign, const std::string& number);
    StrInt(const long long& number): sign(number < 0 ? '-' : '+'), val(std::to_string(abs(number))){};
    friend StrInt operator + (StrInt left,  StrInt right);
    friend StrInt operator - (StrInt left,  StrInt right);
    friend StrInt operator * (StrInt left,  StrInt right);
    friend StrInt operator / (StrInt left,  StrInt right);
    friend StrInt operator % (StrInt left,  StrInt right);
    friend bool operator < (StrInt left,  StrInt right);
    friend bool operator > (StrInt left,  StrInt right);
    friend bool operator == (StrInt left,  StrInt right);
    bool operator!() const;
    StrInt  operator-() {
        return StrInt(this->sign == '+' ? '-' : '+', this-> val);
    };
    static std::string gcd(std::string left,  std::string right);
    
};

StrInt::StrInt(): sign('+'), val(""){}
StrInt::StrInt(const std::string& number){
    std::string tmp;
    if (number[0] == '+'){
         tmp = number.substr(1);
        this->sign = '+';
    }
    else if (number[0] == '-'){
         tmp = number.substr(1);
        this->sign = '-';
        }
    else { tmp = number;this->sign = '+';}
    
    for (char i : tmp) {
        if (!isnumber(i)) {
            throw "NOT digit!";
        }
    }
    
    this->val = tmp;
}

StrInt::StrInt(char sign, const std::string& number){
    if (sign == '+' || sign == '-'){
        this->sign = sign;
    }
    else throw "it's not a - or +";
    
    
    for (char i : number) {
        if (!isnumber(i)) {
            throw "NOT digit!";
        }
    }
    
    this->val = number;
}

std::ostream& operator<<(std::ostream& cout, StrInt::cmpr m)
{
    if (m == StrInt::cmpr::smaller)
        cout << "smaller";
    if (m == StrInt::cmpr::bigger)
        cout << "bigger";
    if (m == StrInt::cmpr::equal)
        cout << "equal";
    cout << std::endl;
    return cout;
}

StrInt::cmpr operator <( std::string left,  std::string right)
{
    if (left.length() > right.length()) {return StrInt::cmpr::bigger;}
    if (left.length() < right.length()) {return StrInt::cmpr::smaller;}
    for (int i = 0; i < left.length(); i++) {
        if (left[i] > right[i]) {return StrInt::cmpr::bigger;}
        else if (left[i] < right[i]) {return StrInt::cmpr::smaller;}
    }
    return StrInt::cmpr::equal;;
    
}


bool StrInt::operator!() const {
    return this->get_val() != "0";;
}


std::string StrInt::plus_str(const std::string& left_arg, const std::string& right_arg)
{
    unsigned long End_len;
    std::string result;
    if (left_arg.length() > right_arg.length())
    {
        End_len = left_arg.length();
    }
    else
    {
        End_len = right_arg.length();
    }
    
    int overflow = 0;
    
    End_len+=1;
    for (auto i = 0; i < End_len; i++)
    {
        //overflow = 0;
        char tmp1;
        if (left_arg.length() > i) {
            tmp1 = left_arg[left_arg.length() - i - 1];
        } else {
            tmp1 = '0';
        }
        char tmp2;
        if (right_arg.length() > i) {
            tmp2 = right_arg[right_arg.length() - i - 1];
        } else {
            tmp2 = '0';
        }

        auto tmp = (tmp1 - '0') + (tmp2 - '0') + overflow;
        overflow = tmp / 10;
        tmp = char(tmp % 10 + '0');
        //result.insert (0,  std::string(1, tmp));
        //result = (std::string(1, tmp)).append(result);
        result = std::string(1, tmp) + result;
    }
    
    if (overflow)
    {
        result = std::string("1").append(result);
    }
    //result.erase(std::remove(result.begin(), result.end(), '0'), result.end());
    
    while(result.length() > 1 && result[0] == '0') {
        result.erase(result.begin());
    }
    //result = std::string(result).append("\0");
    

    //std::cout << "result: " << result  << " : "   << "\n" << std::endl;
    return result;
}


std::string StrInt::minus_str( std::string left,  std::string right){
    
    if ((left < right) == StrInt::cmpr::smaller) {
        std::string tmp = left;
        left = right;
        right = tmp;

    }
    int transfer = 0;
    std::string result;
    for (int i = 0; i < left.length(); i++) {
        char tmp1 = left[left.length() - i - 1];
        char tmp2;
        if (right.length() > i) {
            tmp2 = right[right.length() - i - 1];
        } else {
            tmp2 = '0';
        }
        auto tmp = tmp1 - tmp2 - transfer;
        if (tmp < 0) {
            transfer = 1;
        } else {
            transfer = 0;
        }
        tmp = char((10 + tmp) % 10 + '0');//if < 0
        
        result = std::string(1, tmp) + result;
    }
    
    while(result.length() > 1 && result[0] == '0') {
        result.erase(result.begin());
    }
    return result;
    return "";}

std::string StrInt::multiply_str( std::string left,  std::string right){
    
    if (left == "0" || right == "0")
        return "0";
    if ((left < right) == StrInt::cmpr::bigger) {
        std::string tmp = left;
        left = right;
        right = tmp;

    }
    left = minus_str(left, "1");
    std::string tmp = right;
    while (left != "" && left != "0" ){
        right = plus_str(right, tmp);
        left = minus_str(left, "1");
        while(left.length() > 1 && left[0] == '0') {left.erase(left.begin());}
    }
    return right;
    return "";}

std::tuple <std::string, std::string> StrInt::delete_str( std::string left,  std::string right){
    std::string tmp1 = left;
    std::string tmp2 = right;
    std::string counter = "0";
    while ((left < right) == StrInt::cmpr::bigger || (left < right) == StrInt::cmpr::equal){
        left = minus_str(left, right);
        counter = plus_str(counter, "1");
        while(left.length() > 1 && left[0] == '0') {left.erase(left.begin());}
        
    }
    //auto t = std::make_tuple(counter, left);
    return std::make_tuple (counter, left);
//    return "";
    
}

std::string StrInt::gcd(std::string left,  std::string right)
{
    if (left == "0")
        return right;
    return gcd(std::get<1>(StrInt::delete_str(right, left)), left);
}

StrInt operator / (StrInt left,  StrInt right) {
    StrInt tmp;
    tmp.set_val(std::get<0>(StrInt::delete_str(left.get_val(), right.get_val())));
    if (left.get_sign() == right.get_sign()){
        if (left.get_sign() == '+')
        {
            tmp.set_sign('+');
        }
        else if (left.get_sign() == '-')
        {
            tmp.set_sign('+');
        }
    }
    else{
            tmp.set_sign('-');
    }
    return tmp;
}

StrInt operator % (StrInt left,  StrInt right) {
    StrInt tmp;
    tmp.set_val(std::get<1>(StrInt::delete_str(left.get_val(), right.get_val())));
    if (left.get_sign() == right.get_sign()){
        if (left.get_sign() == '+')
        {
            tmp.set_sign('+');
        }
        else if (left.get_sign() == '-')
        {
            tmp.set_sign('+');
        }
    }
    else{
            tmp.set_sign('-');
    }
    return tmp;
}







StrInt operator * (StrInt left,  StrInt right) {
    StrInt tmp;
    tmp.set_val(StrInt::multiply_str(left.get_val(), right.get_val()));
    if (left.get_sign() == right.get_sign()){
        if (left.get_sign() == '+')
        {
            tmp.set_sign('+');
        }
        else if (left.get_sign() == '-')
        {
            tmp.set_sign('+');
        }
    }
    else{
            tmp.set_sign('-');
    }
    return tmp;
}

StrInt operator - (StrInt left,  StrInt right) {
    StrInt tmp;
    if (left.get_sign() == right.get_sign()){
        tmp.set_val(StrInt::minus_str(left.get_val(), right.get_val()));
        if ((left.get_val() < right.get_val()) == StrInt::cmpr::smaller){
            if (left.get_sign() == '+')
            {
                tmp.set_sign('-');
            }
            else if (left.get_sign() == '-')
            {
                tmp.set_sign('+');
            }
        }
        else if ((left.get_val() < right.get_val()) == StrInt::cmpr::bigger){
            if (left.get_sign() == '+')
            {
                tmp.set_sign('+');
            }
            else if (left.get_sign() == '-')
            {
                tmp.set_sign('-');
            }
        }
        else if ((left.get_val() < right.get_val()) == StrInt::cmpr::equal){
            tmp.set_sign('+');
        }
    }
    else{ // left.get_sign() != right.get_sign()
        tmp.set_val(StrInt::plus_str(left.get_val(), right.get_val()));
        if ((left.get_val() < right.get_val()) == StrInt::cmpr::smaller){
            if (left.get_sign() == '+')
            {
                tmp.set_sign('+');
            }
            else if (left.get_sign() == '-')
            {
                tmp.set_sign('-');
            }
        }
        else if ((left.get_val() < right.get_val()) == StrInt::cmpr::bigger){
            if (left.get_sign() == '+')
            {
                tmp.set_sign('+');
            }
            else if (left.get_sign() == '-')
            {
                tmp.set_sign('-');
            }
        }
        else {tmp.set_sign('+');}
    }
    return (tmp);
}

StrInt operator + (StrInt left,  StrInt right) {
    StrInt tmp;
    if (left.get_sign() == right.get_sign()){
        tmp.set_val(StrInt::plus_str(left.get_val(), right.get_val()));
        if ((left.get_val() < right.get_val()) == StrInt::cmpr::smaller){
            if (left.get_sign() == '+')
            {
                tmp.set_sign('+');
            }
            else if (left.get_sign() == '-')
            {
                tmp.set_sign('-');
            }
        }
        else if ((left.get_val() < right.get_val()) == StrInt::cmpr::bigger){
            if (left.get_sign() == '+')
            {
                tmp.set_sign('+');
            }
            else if (left.get_sign() == '-')
            {
                tmp.set_sign('-');
            }
        }
        else if ((left.get_val() < right.get_val()) == StrInt::cmpr::equal){
            tmp.set_sign('+');
        }
    }
    else{ // left.get_sign() != right.get_sign()
        tmp.set_val(StrInt::minus_str(left.get_val(), right.get_val()));
        if ((left.get_val() < right.get_val()) == StrInt::cmpr::smaller){
            if (left.get_sign() == '+')
            {
                tmp.set_sign('-');
            }
            else if (left.get_sign() == '-')
            {
                tmp.set_sign('+');
            }
        }
        else if ((left.get_val() < right.get_val()) == StrInt::cmpr::bigger){
            if (left.get_sign() == '+')
            {
                tmp.set_sign('+');
            }
            else if (left.get_sign() == '-')
            {
                tmp.set_sign('-');
            }
        }
        else {tmp.set_sign('+');}
    }
    return (tmp);
}

bool operator < (StrInt left,  StrInt right) {
    if (left.sign == '-' && right.sign == '+') {
        return true;
    } else if (left.sign == '+' && right.sign == '-') {
        return false;
    }
    
    if (left.sign == '-'){
        if (left.get_val() < right.get_val() == StrInt::cmpr::smaller || left.get_val() < right.get_val() == StrInt::cmpr::equal)
            return false;
        else return true;
    }
    else if (left.get_val() < right.get_val() == StrInt::cmpr::bigger || left.get_val() < right.get_val() == StrInt::cmpr::equal)
        return false;
    else return true;
        
}

bool operator > (StrInt left,  StrInt right) {
    if (right < left)
        return true;
    else return false;
}

bool operator == (StrInt left,  StrInt right) {
    return !(left < right) && !(left > right);
}


std::ostream& operator<<(std::ostream& cout, StrInt const& str_c) {
    cout << str_c.get_sign() << str_c.get_val() << std::endl;
    return cout;
}


#endif /* Strint_hpp */
