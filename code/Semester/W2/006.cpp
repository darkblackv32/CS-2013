#include <iostream>
using namespace std;

double pi = 3.14159265;

class Forma
{
public:
    Forma(/* args */) {}
    ~Forma() {}
    virtual double calcularArea() = 0;
    friend ostream &operator<<(ostream &os, Forma &f);
};

ostream &operator<<(ostream& os, Forma& f){
    os << "Area : " << f.calcularArea() << endl;
   return os;
}



class Cuadrado : public Forma
{
private:
    double lado;
public:
    Cuadrado(double _l) : lado{_l}{}
    ~Cuadrado(){}
    double calcularArea(){
        return lado*lado;
    }
};

class Triangulo : public Forma
{
private:
    double base, altura;
public:
    Triangulo(double _b, double _a) : base{_b}, altura{_a}{}
    ~Triangulo() {}
    double calcularArea(){
        return (base*altura) / 2;
    }
};

class Circulo : public Forma
{
private:
    double radio;
public:
    Circulo(double _ra) : radio{_ra}{}
    ~Circulo() {}
    double calcularArea(){
        return pi * (radio*radio);
    }
};




int main (){
    Forma* forma;
    Cuadrado cuadrado(2);
    Triangulo triangulo(2 , 3);
    Circulo circulo(2);
    forma = & cuadrado ;
    forma -> calcularArea();
    cout << *forma << endl;
    forma = &circulo ;
    forma -> calcularArea ();
    cout << *forma << endl ;
}