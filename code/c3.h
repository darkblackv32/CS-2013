// #pragma once
#ifndef C3_H
#define C3_H

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

namespace utec {
    class point_t 
    {
    private:
        int *x, *y=nullptr;     // default declaration
        friend ostream& operator<<(ostream&, const point_t&);
        string id;
    public:
        // DEFAULT CONSTRUCTOR -> 0 args
        point_t(): x{nullptr} /*initializer list*/ 
        {
            // body function
            cout<<"\tdefault constructor\n";
            // x = y = nullptr;
            this->id = "empty point\n";
        };
        // point_t() = default;
        // PARAMETERIZED CONSTRUCTOR
        point_t(int _x, int _y) : x {new int(_x)} 
        {
            cout<<"\tparameterized constructor\n";
            y = new int(_y);
        }

        point_t(const pair<int, int>& par)
        {
            cout<<"\tparameterized constructor pair<int, int>\n";
            // destructuring
            auto [f, s] = par;          // ? what is auto in this line
            cout<<"\t\t"<<f<<" "<<s<<endl;
            // int first = par.first;
            // int second = par.second;
            x = new int(f);
            y = new int(s);
        }
        
        // COPY CONSTRUCTOR
        point_t(point_t& other)
        {
            cout<<"\tcopy constructor\n";

            if (other.x != nullptr)
                this->x = new int(*other.x);
            else
                this->x = nullptr;

            if (other.y)
                y = new int(*other.y);
            else
                y = nullptr;
        }

        // MOVE CONSTRUCTOR
        point_t(point_t&& other)
        {
            cout<<"\tmove constructor\n";

            if (other.x != nullptr)
            {
                this->x = other.x;
                other.x = nullptr;
            }
            else
                this->x = nullptr;

            if (other.y)
            {
                y = other.y;
                other.y = nullptr;
            }    
            else
                y = nullptr;
        }

        // COPY ASSINGNMENT OPERATOR
        point_t& operator=(point_t& other)
        {
            cout<<"\tcopy assignment operator\n";

            if (other.x != nullptr)
                this->x = new int(*other.x);
            else
                this->x = nullptr;

            if (other.y)
                y = new int(*other.y);
            else
                y = nullptr;
            
            // ? return
            point_t& aux = *this;
            return aux;
        }

        // MOVE ASSIGNMENT OPERATOR
        point_t& operator=(point_t&& other)
        {
            cout<<"\tmove assignment operator\n";

            if (other.x != nullptr)
            {
                this->x = other.x;
                other.x = nullptr;
            }
            else
                this->x = nullptr;

            if (other.y)
            {
                y = other.y;
                other.y = nullptr;
            }    
            else
                y = nullptr;
            
            return *this;
        }

        // DESTRUCTORES
        // ~point_t() = default;
        ~point_t(){
            cout<<"\tdestructor\n";
            if (x != nullptr)
                delete x, x = nullptr;
            if (y)          // si esta vivo
                delete y, y = nullptr;
            // x = y = nullptr;         // ? why segmentation fault
        }
    };

    ostream& operator<<(ostream& os, const point_t& p)
    {
        os<<"{";
        if (p.x) os << p.x << " " << *p.x;
        else os << "null";

        os << " | ";

        if (p.y) os << p.y << " " << *p.y;
        else os << "null";
        os << "}";

        return os;
    }
}

/**
 * OBJETO:
 *  instancia de clase
 *  INSTANCIA:
 *      particularizacion
 * CONSTRUCTORES:
 *  metodo especial que se invoca en el momento de la creacion de un objeto
 *      memory allocation
 *      inicializacion de atributos
 *  no tiene tipo de retorno, su nombre es el mismo de la clase
 * DESTRUCTORES:
 *  metodo especial (~) que destruye lo que el constructor construyo xD
 *      liberacion de memoria dinamica (heap)
 *  se invoca cuando se sale del scope al que pertenece el objeto
 * 
 * COPYCONSTRUCTOR:
 *  es llamado cuando se quiere crear un objeto a partir de otro objeto del mismo tipo
 *  crea un espacio de memoria particular para el nuevo tipo que copiara los elementos del otro
 * 
 * MOVECONSTRUCTOR:
 *  mueve los recursos en el heap de un objeto a otro
 *  mover implica dejar vacio a la otra variable (rvalue)
*/

/*
COPY CONSTRUCTOR
    https://www.geeksforgeeks.org/when-is-a-copy-constructor-called-in-cpp/

    It is called when a new object is created from an existing object, 
        as a copy of the existing object
    It creates a separate memory block for the new object

ASSIGNMENT OPERATOR
    https://www.geeksforgeeks.org/copy-constructor-vs-assignment-operator-in-c/

    this operator is called when an already initialized object is assigned a new value from another existing object
    it does not create a separate memory block or new memory space
*/

#endif  // C3_H

