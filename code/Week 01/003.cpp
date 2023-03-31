#include <bits/stdc++.h>
using namespace std;

// lvalue is an expression that refers to an object that has a persistent memory location
// rvalue is an expression that refers to an object that does not have a persistent memory location
class Auto{

private:
    string color;
    double kilometraje;
    friend void detalles_tecnicos(const Auto& a);
public:
    Auto(string n_col, double n_kil) : color(n_col), kilometraje(n_kil){};
    
    void manejar(const Auto& a){
        a.kilometraje += 5;
    }
    
    friend void detalles_tecnicos(const Auto& a);
   
};

    void detalles_tecnicos(const Auto& a){
        cout << "Color: " << a.color << endl;
        cout << "Kilometraje: " << a.kilometraje << endl;
    }

int main(){ 

    Auto a("Rojo", 100);

    a.manejar(a);
    a.manejar(a);

    detalles_tecnicos(a);


    return 0;
}