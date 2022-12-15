#include "c2.h"
using namespace std;

void referencias(), constant();

int main(){
    // constant();
    referencias();
}




void referencias(){

    int var2 = 20;
    const int& ref_var2 = var2;     // referencia constante a un lvalue
    // !cout << ref_var2 <<endl; 20
    cout<<sizeof(ref_var2)<<" -> "<<&ref_var2<<" "<<&var2<<endl; // ambas direcciones son iguales ya que ref_var2 es solo otra forma de llamar a var2
    // todo | ref_var2 = 10  es error ref_var2 es un int const no se puede modificar

    const int& ref_20 = 20;         // referencia constante a un rvalue
    cout<<&ref_20<<" "<<endl; // da direccion de memoria

    int var1 = 10;
    int& lref = var1;
    int&& rref = 20; // declara una referencia rvalue (creo que reemplaza al const&)
    // https://stackoverflow.com/questions/5481539/what-does-t-double-ampersand-mean-in-c11

    cout<<lref<<" | "<<rref<<endl;
    lref = rref;        // lref = 20
    rref = var1;        // rref = 10, doesn't return error (en teoria deberia dar error porque rref es const pero como tiene el && no da)
    cout<<lref<<" | "<<rref<<endl; //rref no cambia el valor porque es const (&&)
    rref = 40; // esto nos lo permite el &&?? no estoy seguro
    // creo que permite el cambio dado que solo pone rref y no &rref o &&rref
    cout<<lref<<" | "<<rref<<endl;

}


void constant(){

/* CONST: Whenever const keyword is attached with any method(), variable, pointer variable, and with the object
 of a class it prevents that specific object/method()/variable to modify its data items value.*/

// How to declare it...
    const int var = 8;
    // WRONG : const int var;
    // WRONG : const int var
    // var = 5;

    //with pointers
    const int* v1;

    int na = 5;
    int* const v2 = &na;

    int x{ 10 };
    char y{ 'M' };
 
    const int* i = &x;
    const char* j = &y;

    // *j = 'B'; WRONG
    

    char v3{ 'A' };
    const char* const z = &v3;


    // Value of x and y can be altered,
    // they are not constant variables
    x = 9;
    y = 'A';
 
    // Change of constant values because,
    // i and j are pointing to const-int
    // & const-char type value
    // we cannot change *i and *j cos they are constant values
    // *i = 6;
    // *j = 7;
 
    cout << *i << " " << *j;


}


