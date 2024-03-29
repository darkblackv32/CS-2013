#include <iostream>
#include <string>
using namespace std;
template<typename T = string>

class smart_ptr
{
private:
    T ptr;
public:
    
    smart_ptr() = default;
    
    template<typename Z>
    smart_ptr(Z _pt) : ptr{_pt}{} 

    template<typename Z>
    smart_ptr(Z _pt, Z _p2){}


    T& operator*(){
        return ptr;
    }

    T& operator->(){
        return *ptr;
    }
    
    ~smart_ptr(){};
};


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

template <typename T, typename U>
    smart_ptr<T> make_smart_ptr(U value){
        return smart_ptr<T>(std::forward<U>(value)); // ? explicado arriba
    // * por ejemplo aca funciona retornando value como un rvalue, pero no lo es del todo ya que esta dentro de la funcion
}        

template <typename T, typename U, typename X>
    smart_ptr<T> make_smart_ptr(U &&arg1, X &&arg2){
        return smart_ptr<T>(std::forward<U>(arg1), std::forward<X>(arg2));  
}  

// template <typename T, typename U>
//     smart_ptr<T> make_smart_ptr(U arg1, U arg2){
//         return smart_ptr<T>(std::forward<U>(arg1), std::forward<U>(arg2)); 
// }  




// template <typename T, typename U, typename X>
//     smart_ptr<T> make_smart_ptr(U &&arg1, X &&arg2){
//         return smart_ptr<T>(std::forward<U>(arg1), std::forward<X>(arg2));  //? funciona, pero solo una vezxd q random

// }  

// template <typename T, typename ...U>
//     smart_ptr<T> make_smart_ptr(U... args){
//         return smart_ptr<T>(std::forward<U...>(args...));  

// } 