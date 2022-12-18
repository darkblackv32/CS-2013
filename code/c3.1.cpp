#include "c3.1.h"
using namespace messi;
#define pb push_back     // MACRO

void ex1(), ex2(), references();

int main(){
    ex1();
    references();
    ex2();
   
}

void ex1(){

    dimensiones d0;
    cout<<d0<<endl;

    dimensiones d1(172.43,86.6);
    cout<<d1<<endl;

    pair<float, float> par(189.32, 88.78);
    dimensiones d2(par);
    cout<<d2<<endl;

    dimensiones d3(d2), d4 = d2; // no hemos sobrecargado el = pero eso no impide que funcione si usamos el constructor copia, el problema es que este = solo puede ser utilizado en la declaración
    cout<<"        d2 -> " << d2 << endl;
    cout<<"        d3 -> " << d3 <<endl;
    cout<<"        d4 -> " << d4 <<endl;
    
    d4 = d2;

    dimensiones d5;
    d5 = d3; // COPY ASSIGNMENT

    cout<<"        d4 -> " << d4 << endl;
    cout<<"        d5 -> " << d5 <<endl;

}

void references()
    {
    dimensiones d0;         // * lvalue: tiene asignado una porcion de memoria
    // REFERENCIA A UN LVALUE
    dimensiones& lref = d0;
    
    // point_t& lref_error = point_t(179.7, 76.42);

    // REFERENCIA A UN RVALUE
    dimensiones&& rref = dimensiones(179.7, 76.42);

    // point_t(4, 5) + point_t(5, 7) = point_t(9, 8);
    // point_t(4, 5) = point_t(7, 9);
    }

void ex2()
{
    vector<dimensiones> dimen;
    dimen.pb(dimensiones(195.67, 91)); // se utiliza el move cuando se mueve al vector
    cout<<dimen[0]<<endl;

    cout<<dimen.size()<<" "<<dimen.capacity()<<endl;
    dimen.pb(dimensiones(195.67, 91.45));
    cout<<dimen.size()<<" "<<dimen.capacity()<<endl;
    dimen.pb(dimensiones(160.21, 50.12)); 
    cout<<dimen.size()<<" "<<dimen.capacity()<<endl;
    dimen.pb(dimensiones(185.97, 71.98)); 
    cout<<dimen.size()<<" "<<dimen.capacity()<<endl;
    dimen.pb(dimensiones(165.17, 57.43)); 
    cout<<dimen.size()<<" "<<dimen.capacity()<<endl;
    dimen.pb(dimensiones(152.23, 47.54));
    cout<<dimen.size()<<" "<<dimen.capacity()<<endl;
    dimen.pb(dimensiones(174.43, 88.21));  
    cout<<dimen.size()<<" "<<dimen.capacity()<<endl;
    dimen.pb(dimensiones(187.91, 77.09));  
    cout<<dimen.size()<<" "<<dimen.capacity()<<endl;
    dimen.pb(dimensiones(196.87, 67.12));
    cout<<dimen.size()<<" "<<dimen.capacity()<<endl;
    dimen.pb(dimensiones(205.32, 41.34));   

    /*recordar que los moves se dan cuando movemos cada elemento al vector, deja el lugar donde estaba vacio y llena el
    espacio de memoria del vector*/

    cout<<dimen[5]<<endl;
    dimen[5] = dimensiones(110.12, 57.54);        // * MOVE ASSIGNMENT (rvalue)
    cout<<dimen[5]<<endl;

    dimensiones d_ex;
    d_ex = dimensiones(180.32, 89.93);        // * MOVE ASSIGNMENT (rvalue)
    cout<<d_ex<<endl;
    
}