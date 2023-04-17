#include <bits/stdc++.h>
using namespace std;

class Auto{

private:
    string color;
    int precio;
    int kilometraje = 0;
    friend void detalles_tecnicos(const Auto& a);
public:
    Auto(string n_col, int n_pr) : color(n_col), precio(n_pr){};
    
    Auto(Auto& n_auto){
        color = n_auto.color;
        precio = n_auto.precio;
        kilometraje = n_auto.kilometraje;
    }

    void viajar(int km){
        kilometraje += km;
        cout << "Los km recorridos hasta el momento son : "<< kilometraje << endl;
    }
    
    friend void mostrar(const Auto& a);
   
};

    void mostrar(const Auto& a){
        cout << "Color: " << a.color << endl;
        cout << "Kilometraje: " << a.kilometraje << endl;
        cout << "Precio: " << a.precio << endl;
    }

int main(){ 

    Auto a("Rojo", 15245);

    a.viajar(17);
    cout << endl;
    mostrar(a);

    Auto b(a);

    b.viajar(298);
    cout << endl;
    mostrar(b);


    return 0;
}