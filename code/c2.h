#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <utility>

// NAMESPACE: collection of related names or identifiers
// evitar ambiguedad
namespace soldi {
    class vint;

    // AMISTAD entre una clase y un método especifico de una clase
    class dint {
    private:
        int* arr = nullptr;
        int size = 0;
        // AMISTAD entre 1 funcion y una clase
        friend std::ostream& operator<<(std::ostream& os, const dint& v);
    public:
        dint() = default;

        dint(int _size, int _default)
        {
            this->size = _size;
            this->arr = new int[this->size];
            for (int i=0; i<this->size; ++i)
                *(this->arr + i) = _default;
        }

        int sz(){ return this->size;}

        int& operator[](int pos)
        {
            if (pos >= this->size)
                throw std::runtime_error("index out of bounds\n");
            return this->arr[pos];
        }

        void copy_from_vint(vint&);
    };

    class vint {
    private:
        int* arr = nullptr;
        int size = 0;
        // AMISTAD entre 1 funcion y una clase
        friend std::ostream& operator<<(std::ostream& os, const vint& v);
        friend void dint::copy_from_vint(vint&);
    public:
        vint() = default;

        vint(int _size, int _default)
        {
            this->size = _size;
            this->arr = new int[this->size];
            for (int i=0; i<this->size; ++i)
                *(this->arr + i) = _default;
        }
    };

    std::ostream& operator<<(std::ostream& os, const vint& v)
    {   // referencia de solo lectura
        os<<"[ ";
        for (int i=0; i<v.size; ++i)
            os<<v.arr[i]<<" ";
        os<<"]";
        return os;
    }

    std::ostream& operator<<(std::ostream& os, const dint& v)
    {   // referencia de solo lectura
        os<<"[ ";
        for (int i=0; i<v.size; ++i)
            os<<v.arr[i]<<" ";
        os<<"]";
        return os;
    }

    void dint::copy_from_vint(vint& v)
    {
        this->size = v.size;
        this->arr = new int[this->size];
        for (int i=0; i<this->size; ++i)
            this->arr[i] = v.arr[i];        // failed attempt, this->[i]
    }
}