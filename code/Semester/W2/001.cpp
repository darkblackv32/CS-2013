#include <bits/stdc++.h>
using namespace std;

class Pj
{
private:
    string nombre;
    string raza;
    int vida;
    int ataque;
    friend istream &operator>> (Pj& p, Pj& p2);
    friend Pj &operator+(Pj& p, int x);
    friend ostream &operator<<(ostream &os, Pj &p);
public:
    Pj(string _n, string _r, int _v, int _a) : nombre(_n), raza(_r), vida(_v), ataque(_a) {}
    ~Pj(){}
};

istream &operator>> (Pj& p, Pj& p2){
    p2.vida -= p.ataque;
    return cin;
}

Pj &operator+(Pj& p, int x){
    p.vida += x;
    return p;
} 

ostream &operator<<(ostream &os, Pj &p){
    os << "Nombre: " << p.nombre << endl;
    os << "Raza : " << p.raza << endl;
    os << "Vida: " << p.vida << endl;
    os << "Ataque: " << p.ataque << endl;
    return cout;
}


int main (){
    // Crear personajes ( nombre , raza , vida , ataque )
    Pj orco ( "Orgrim" , "Orco" , 100 , 35);
    Pj humano ( "Arthas" , "Humano" , 100 , 22);
    Pj elfo ( "Legolas" , "Elfo" , 100 , 63);
    // Ataque de orco a humano
    orco >> humano ;
    // Recuperar vida de elfo
    elfo + 10;
    cout << humano ;
    cout << endl;
    cout << elfo;
}

