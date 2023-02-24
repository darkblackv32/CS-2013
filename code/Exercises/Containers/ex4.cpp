#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Hora
{
private:
    int h;
    int min;
    int seg;
    friend ostream& operator <<(ostream& os, const Hora& time);
public:
    Hora(){}
    Hora(int _h, int _min, int _seg) : h{_h}, min{_min}, seg{_seg}{}
    ~Hora(){}
};

    ostream& operator <<(ostream& os, const Hora& time){
        os << time.h << ":" << time.min << ":" << time.seg << endl;
        return os;
    }


class Fecha
{
private:
    int d;
    int m;
    int y;
    friend ostream& operator <<(ostream& os, const Fecha& date);
public:
    Fecha(){}
    Fecha(int _d, int _m, int _y) : d{_d}, m{_m}, y{_y} {}
    ~Fecha(){}
};
    
    ostream& operator <<(ostream& os, const Fecha& date){
        os << date.d << "/" << date.m << "/" << date.y << endl;
        return os;
    }

class Agenda
{
private:
    list<pair<Fecha, Hora>> eventos;
    vector<string> des;
public:
    Agenda(){}
    ~Agenda(){}

    void insertar_evento(const Fecha &fecha, const Hora &Hora,
    const std::string& descripcion){
        eventos.emplace_back(&fecha).first;
        eventos.emplace_back(&Hora).second;
        des.emplace_back(&descripcion);
    }

    std::list<std::pair<Hora, std::string>> eventos_dia(const Fecha &fecha){
        list<pair<Hora, string>> lt1;
        for(const auto& i : eventos){
            if(i.first == fecha){
                
            }
        }
        
        
        return lt1;

    }
    
};


int main(){

    Agenda agenda;
    
    Fecha f1(28,02,23);
    Hora h1(17,40,00);

    agenda.insertar_evento(f1,h1,"Sacar a pasear al perro");

    cout << f1;
    cout << h1;
    return 0;
}