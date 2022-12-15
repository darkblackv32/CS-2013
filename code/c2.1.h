#pragma once
#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <deque>
#include <utility>

namespace jj{ // lo usamos para evitar ambiguedad
    
    // AMISTAD entre 1 funcion y una clase

    /*ahora vamos a realizar una operacion similar pero usando una lista*/
    class vflo;

    class dint // unsigned long int vector
    {
    private:
        int* arr = nullptr;
        int size = 0;
        friend std::ostream& operator<<(std::ostream& os, const dint& v);

    public:
        dint() = default;
        
        dint(int _sz, int _def){
            this->size = _sz;
            this->arr = new int[this->size];
            for (int i=0; i<this->size; ++i)
                *(this->arr + i) = _def; // lenamos todas las posiciones con el valor default
        }

        int sz(){return this->size;}

        int& operator[](int pos){
            if (pos >= this->size)
                throw std::runtime_error("index out of bounds\n");
            return this->arr[pos];
        }
        
        void copy_from_dint(vflo& v);
    };

    

    std::ostream& operator<<(std::ostream& os, const dint& v){   
        // referencia de solo lectura
        os<<"[ ";
        for(int i = 0; i < v.size; ++i)
            os<<v.arr[i]<<" ";
        os<<"]";
        return os;
    }
   
   

    class vflo // unsigned long int vector
    {
    private:
        float* arr = nullptr;
        int size = 0;
        friend std::ostream& operator<<(std::ostream& os, const vflo& v);
        friend void dint::copy_from_dint(vflo&);
    public:
        vflo() = default;
        
        vflo(int _sz, float _def){
            this->size = _sz;
            this->arr = new float[this->size];
            for (int i=0; i<this->size; ++i)
                *(this->arr + i) = _def; // lenamos todas las posiciones con el valor default
        }

    };

    std::ostream& operator<<(std::ostream& os, const vflo& v){   
        // referencia de solo lectura
        os<<"[ ";
        for(int i = 0; i < v.size; ++i)
            os<<v.arr[i]<<" ";
        os<<"]";
        return os;
    }

    void dint::copy_from_dint(vflo& v){
            this->size = v.size;
        this->arr = new int[this->size];
        for (int i=0; i<this->size; ++i)
            this->arr[i] = v.arr[i];  
    };
    





}