#pragma once 

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

namespace messi {
    class dimensiones
    {
    private:
        float *talla = nullptr, *peso; //?default declaration
        string nombre;
        friend ostream& operator<<(ostream& os, const dimensiones& d);
    public:
        // ! CONSTRUCTORS
        // todo ~ DEFAULT CONSTRUCTOR -> 0 args
        dimensiones() : peso{nullptr}
        {
            //body function 
            cout<<"default constructor\n";
            this->nombre = "empty name\n";  
        }
        

        // todo ~ PARAMETERIZED CONSTRUCTOR
        dimensiones(float _talla, float _peso) : talla {new float(_talla)}
        {   
            cout<<"parameterized constructor\n";
            peso = new float(_peso);
        }

        // todo ~ PARAMETERIZED CONSTRUCTOR pair<float, float>";
        dimensiones(const pair<float, float>& par)
        {
            cout<<"parameterized constructor pair<float, float>\n";
            // destructuring
            auto [t, p] = par; //? the type of auto here is a mystery, in cppreference and in a lot of other pages is described as here, they just use auto
            cout<<"\t\t"<<"Height: " << t << " " <<"Weight: " << p << endl;
            talla = new float(t);
            peso = new float(p);
        }

        // todo ~ COPY CONSTRUCTOR
        dimensiones(dimensiones& other)
        {
            cout<<"copy constructor\n";

            if (other.talla != nullptr)
                this->talla = new float(*other.talla);
            else 
                this->talla = nullptr;
            
            if(other.peso) // == other.peso != nullptr
                peso = new float(*other.peso);
            else
                peso = nullptr;
        }

        // todo ~ COPYT ASSINGMENT OPERATOR
        dimensiones& operator=(dimensiones& other)
        {
            cout<<"copy assignment operator\n";

            if (other.talla != nullptr)
                this->talla = new float(*other.talla);
            else 
                this->talla = nullptr;
            
            if(other.peso) // == other.peso != nullptr
                peso = new float(*other.peso);
            else
                peso = nullptr;

            // ? return
            dimensiones& aux = *this; // se retorna asi mismo 
            // ! A TI MISMO ES A QUIEN LE COPIAS LOS VALORES
            return aux;

        }

        // todo ~ MOVE CONSTRUCTOR
        dimensiones(dimensiones&& other)
        {
            cout<<"move constructor\n";

            if(other.talla) //  == other.talla != nullptr
            {
                talla = other.talla;
                other.talla = nullptr;
            }
            else 
                this->talla = nullptr;

            if (other.peso)
            {
                peso = other.peso;
                other.peso = nullptr;
            }
            else
                peso = nullptr;
        }

        // todo ~ MOVE ASSINGMENT CONSTRUCTOR
        dimensiones& operator=(dimensiones&& other)
        {
            cout<<"move assignment constructor\n";

            if(other.talla) //  == other.talla != nullptr
            {
                talla = other.talla;
                other.talla = nullptr;
            }
            else 
                this->talla = nullptr;

            if (other.peso)
            {
                peso = other.peso;
                other.peso = nullptr;
            }
            else
                peso = nullptr;
            
            return *this;
        }

        // ! DESTRUCTORS
        ~dimensiones(){
            cout<<"\tdestructor\n";
            if (talla != nullptr)
                delete talla, talla = nullptr;
            if (peso) // == peso != nullptr
                delete peso, peso = nullptr;
        }           
        
    };


    ostream& operator<<(ostream& os, const dimensiones& d){
        os<<"       {";
        if (d.talla) os << "Memory Address: " << d.talla << " " << "Height(cm): " << *d.talla;
        else os  << "no data";

        os << " | ";

        if (d.peso) os << "Memory Address: " << d.peso << " " << "Weight(kg): " << *d.peso;
        else os << "no data";
        os << "}";

        return os;
    }
}

    