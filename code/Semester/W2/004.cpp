#include <bits/stdc++.h>
using namespace std;


class Item
{
private:
    /* data */
public:
    Item() = default;
    virtual int usar() = 0;
    ~Item() {}
};

class Carne : public Item
{
private:
    /* data */
public:
    Carne() {}
    ~Carne() {}
    int usar(){
        return 100;
    }
};

class Agua  : public Item
{
private:
    /* data */
public:
    Agua(/* args */) {}
    ~Agua() {}
    int usar(){
        return 100;
    }
};

class Magia : public Item
{
private:
    /* data */
public:
    Magia(/* args */) {}
    ~Magia() {}
    int usar(){
        return 100;
    }
};



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

    void curar(Item &i){
        vida = i.usar();
    }
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
    Pj pj1 ( " Orgrim " ," Orco " ,15 ,20); // Se cura con Carne
    Pj pj2 ( " Legolas " ," Elfo " ,60 ,35); // Se cura con Magia
    Pj pj3 ( " Aragorn " ," Humano " ,80 ,25); // Se cura con Agua

    Carne carne ;
    Agua agua ;
    Magia magia ;

    pj1.curar(agua);
    cout << pj1 << pj2 << pj3 ;
    return 0;
    }

