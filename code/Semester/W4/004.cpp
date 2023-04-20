#include <iostream>
using namespace std;

template<typename T>
string Tipo(T a){ return "No es puntero. ";}

template<typename T>
string Tipo(T* a){ return "Es puntero. ";}

template<>
string Tipo(int* a){ return "Es puntero int. ";}


int main(){
    int a = 1;
    int* b = &a;
    cout << Tipo(a) << endl;
    cout << Tipo(b) << endl;
    cout << Tipo(&a) << endl;

    double c = 2.324425;
    double* c1 = &c;
    cout << Tipo(c) << endl;
    cout << Tipo(c1) << endl;
    
    float* q1;
    cout << Tipo(q1) << endl;
    
    return 0;
}