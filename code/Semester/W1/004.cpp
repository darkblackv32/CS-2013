#include <bits/stdc++.h>

using namespace std;

class Personaje{
private:

    string nombre;
    int vida;
    int ataque;
    int defensa;
    int magia;
    friend ostream &print(ostream &os, const Personaje &p);
public:
    Personaje(string n, int v, int a, int d, int m) : nombre(n), vida(v), ataque(a), defensa(d), magia(m){};
    Personaje() : nombre(""), vida(0), ataque(0), defensa(0), magia(0){};
    ~Personaje(){};
    Personaje(Personaje& p){
        nombre = p.nombre;
        vida = p.vida;
        ataque = p.ataque;
        defensa = p.defensa;
        magia = p.magia;
    }

    void cambiar_nombre(string n){
        nombre = n;
    }

    
};
    
ostream &print(ostream &os, const Personaje &p){

    cout << "Nombre: " << p.nombre << endl;
    cout << "Vida: " << p.vida << endl;
    cout << "Ataque: " << p.ataque << endl;
    cout << "Defensa: " << p.defensa << endl;
    cout << "Magia: " << p.magia << endl;

    return os;
}



int main(){

    Personaje p("Juan", 100, 15, 12, 01);

    Personaje p2(p);

    p2.cambiar_nombre("Pedro");

    print(cout, p2);

    return 0;
}