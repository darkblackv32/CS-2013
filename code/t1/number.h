#pragma once
#include <iostream>
using namespace std;

class number_t
{
private:
    int* x;
public:
    number_t(int _x): x {new int(_x)}{}; 
    ~number_t(){}
};

class integer_t : protected number_t
{
private:
    
public:
    integer_t(int _x): number_t(_x){}; 
    ~integer_t(){}
};

class real_t : protected number_t
{
private:
    
public:
    real_t(int _x): number_t(_x){}; 
    ~real_t(){}
};

class complex_t : protected number_t
{
private:
    
public:
    complex_t(int _x): number_t(_x){}; 
    ~complex_t(){}
};