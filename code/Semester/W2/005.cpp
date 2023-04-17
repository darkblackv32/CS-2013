#include <iostream>
using namespace std;





class Item
{
private:
    int ataque;
public:
    Item() {}
    ~Item() {}
    virtual int at() = 0;
    
};

class Hacha : public Item
{
private:
    /* data */
public:
    Hacha() {}
    ~Hacha() {}
    int at(){
        return 20;
    }
};

class Arco : public Item
{
private:
    /* data */
public:
    Arco() {}
    ~Arco() {}
    int at(){
        return 52;
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

    // void curar(Item &i){
    //     vida = i.usar();
    // }

    void atacar(Item &i, Pj &p){
        p.vida -= i.at();
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


int main(){

    Pj pj1 ( " Orgrim " , " Orco " , 100 , 20);
    Pj pj2 ( " Legolas " , " Elfo " , 60 , 35);
    Pj pj3 ( " Aragorn " , " Humano " , 80 , 25);
    Hacha hacha ;
    Arco arco ;
    pj1.atacar(hacha, pj2); // hacha - 20
    pj2.atacar(arco, pj3);  // arco - 52
    cout << pj1 << pj2 << pj3 ;

}
