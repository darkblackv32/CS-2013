#include <iostream>
using namespace std;

class Hora
{
private:
    /* data */
public:
    Hora(/* args */) {}
    ~Hora() {}
};
class Fecha
{
private:
    /* data */
public:
    Fecha(/* args */) {}
    ~Fecha() {}
};

class Agenda
{
private:
    Fecha fe;
    Hora h;
public:
    Agenda(){}
    Agenda(Fecha fe, Hora h){}
    ~Agenda(){}

    void insertar_evento(const Fecha &fecha, const Hora &Hora,
    const std::string& descripcion);
};


int main(){



    return 0;
}