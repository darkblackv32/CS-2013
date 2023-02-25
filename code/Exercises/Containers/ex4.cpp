#include <iostream>
#include <list>
#include <map>
#include <utility> 

using namespace std;

class Fecha {
public:
    int day, month, year;
    bool operator<(const Fecha& other) const{
        if (year != other.year)
            return year < other.year;
        if (month != other.month)
            return month < other.month;
        return day < other.day;
    }
};

class Hora {
public:
    int hora, minutos;
    bool operator<(const Hora& other) const{
        if (hora != other.hora)
            return hora < other.hora;
        return minutos < other.minutos;      
    }
};

class Agenda {
private:
    map<Fecha, list<pair<Hora, string>>> eventos;
public:
    void insertar_evento(const Fecha &fecha, const Hora &hora, const string& descripcion) {
        eventos[fecha].emplace_back(hora, descripcion);
    }

    list<pair<Hora, string>> eventos_dia(const Fecha &fecha) {
        if (eventos.count(fecha) == 0) {
            return list<pair<Hora, string>>();
        }

        list<pair<Hora,string>>& lista_eventos = eventos[fecha]; 
        lista_eventos.sort();

        return lista_eventos;
    }

    list<pair<Hora, string>> eventos_dia(const Fecha &fecha, const Hora &desde, const Hora &hasta) {
        if (eventos.count(fecha) == 0) {
            return list<pair<Hora, string>>();
        }

        auto& lista_eventos = eventos[fecha];
        lista_eventos.sort();

        list<pair<Hora, string>> eventos_en_rango;

        for (auto& evento : lista_eventos) {
            if (evento.first.hora >= desde.hora && evento.first.hora <= hasta.hora) {
                eventos_en_rango.emplace_back(evento.first, evento.second);
            }
        }

        return eventos_en_rango;
    }

};

int main() {
    
    Agenda mi_agenda;

    mi_agenda.insertar_evento({24, 2, 2023}, {8, 30}, "Graph Theory Review");
    mi_agenda.insertar_evento({28, 2, 2023}, {10, 0}, "Programming III");
    mi_agenda.insertar_evento({29, 2, 2024}, {15, 30}, "Russian class");
    mi_agenda.insertar_evento({24, 2, 2023}, {19, 0}, "Deep Learning Class");

    cout << "Eventos del 24/02/2023:" << endl;

    auto eventos_del_dia = mi_agenda.eventos_dia({24, 2, 2023});

    for (auto& evento : eventos_del_dia) {
        cout << evento.first.hora << ":" << evento.first.minutos << " - " << evento.second << endl;
    }

    cout << endl;

    cout << "Eventos del 24/02/2023 entre las 12:00 y las 19:00:" << endl;

    auto eventos_en_rango = mi_agenda.eventos_dia({24, 2, 2023}, {12, 0}, {19, 0});

    for (auto& evento : eventos_en_rango) {
        cout << evento.first.hora << ":" << evento.first.minutos << " - " << evento.second << endl;
    }

    return 0;
}