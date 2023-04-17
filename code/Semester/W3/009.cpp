#include <iostream>
#include <vector>
#include <list>

using namespace std;

template<template<class>class C, class T>
void print_poly(C<T> coef){
    int size = distance(coef.begin(), coef.end())-1;
    int exp  = size;
    for(auto elemento: coef){
        if (elemento >= 0 and exp!=size)
            cout << "+";
        cout<<elemento;
        if (exp > 0)
            cout<<"x^"<<exp;
        exp--;
    }
    cout << endl;
}

int main(){
    vector<int> v1{3,2,7};
    vector<float> v2{0.1,-3.2, 1.1};
    list<float> l1{2.1,-2.2, 4.4, 4.1};

    print_poly<vector, int>(v1); // Resultado: 3x^2+2x^1+7
    print_poly<vector, float>(v2); // Resultado: 0.1x^2-3.2x^1+1.1
    print_poly<list, float>(l1); // Resultado: 2.1x^3-2.2x^2+4.4x^1+4.1
}