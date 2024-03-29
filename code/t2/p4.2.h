#pragma once
#include <iostream>
using namespace std;
class point {
    int x = 1;
    int y = 2;
public:
    point() = default;
    point(int _x, int _y): x{_x}, y{_y} {}
    
    friend ostream& operator<< (ostream& os, const point& p)
    {
        os << "{" << p.x <<", " << p.y << "}" << endl;
        return os;
    }
    
    int get_x() { return x; }
    int get_y() { return y; }
};

template<class T = string>
class smart_ptr
{
private:
    T* ptr = nullptr;
public:
    
    smart_ptr() = default;

    template<typename... P>
    smart_ptr(P... pack) {
        this->ptr = new T(pack...);
        // cout << (*ptr).get_x() << endl;
        // cout << ptr->get_y() << endl;
    }

    T& operator*(){ return *ptr; }
    T*& operator->(){ return ptr; }

    ~smart_ptr(){};
};

template<typename T, typename... P>
smart_ptr<T> make_smart_ptr(P... pack)
{
    return smart_ptr<T>(pack...);
}

/* std::forward 
        Returns an rvalue reference to arg if arg is not an lvalue reference.
        If arg is an lvalue reference, the function returns arg without modifying its type.
        This is a helper function to allow perfect forwarding of arguments taken as rvalue references to deduced types,
        preserving any potential move semantics involved.
        The need for this function stems from the fact that all named values (such as function parameters) always evaluate
        as lvalues (even those declared as rvalue references), and this poses difficulties in preserving potential move 
        semantics on template functions that forward arguments to other functions. 
        
        std::forward is a function template that is used to pass arguments to a function or constructor as either lvalue 
        or rvalue references, depending on the type of the original argument.
        */

//! BÁSICAMENTE PERMITE QUE PONDAMOS ASIGNAR UN LVALUE A UN LVALUE DEL MISMO TIPO COMO SI FUERA UN RVALUE

// con ambos parametros del mismo tipo
// template <typename T, typename U>
//     smart_ptr<T> make_smart_ptr(U value){
//         return smart_ptr<T>(std::forward<U>( value)); // ? explicado arriba
//     // * por ejemplo aca funciona retornando value como un rvalue, pero no lo es del todo ya que esta dentro de la funcion
// }        

// con dos parametros de distinto tipo
// template <typename T, typename U, typename X>
//     smart_ptr<T> make_smart_ptr(U arg1, X arg2){
//         return smart_ptr<T>(std::forward<U>(arg1), std::forward<X>(arg2));  
// }  

// template <typename T, typename U>
//     smart_ptr<T> make_smart_ptr(U val1, U val2){
//         return smart_ptr<T>(std::forward<U>(val1), std::forward<U>(val2)); 
// }  


// template <typename T, typename U, typename X>
//     smart_ptr<T> make_smart_ptr(U &&arg1, X &&arg2){
//         return smart_ptr<T>(std::forward<U>(arg1), std::forward<X>(arg2));  //? funciona, pero solo una vezxd q random

// }  

// template <typename T, typename ...U>
//     smart_ptr<T> make_smart_ptr(U... args){
//         return smart_ptr<T>(std::forward<U...>(args...));  

// } 