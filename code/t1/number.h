#pragma once
#include <iostream>
using namespace std;


class number_t
{
private:
    
public:
    
    virtual void out(){};
    // virtual void def(number_t* num){};
    number_t(){};
    ~number_t(){}
    
};


class integer_t : public number_t
{
private:
    int* x;
public:
    void out(){cout << *x;}
    integer_t() = default;
    integer_t(int _x): x{new int(_x)}{};
    ~integer_t(){};

    // void def(number_t* num){
    //     num = new integer_t();

    // }
};
    // number_t* var_name = new integer_t();
    // Recuerda el polimorfismo por puntero


class real_t : public number_t
{
private:
    double* y;
public:
    void out(){cout << *y;}
    real_t() = default;
    real_t(double _y): y{new double(_y)}{};
    ~real_t(){}
    // void def(number_t* num){
    //     num = new real_t();
    // }
};

