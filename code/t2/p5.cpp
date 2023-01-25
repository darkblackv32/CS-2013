#include "p5.h"


int main(){

    std::cout << suma_producto(1, 10, 3, 5) << endl; // El resultado seria: 25

    std::cout << suma_producto(1) << endl; // El resultado seria: 1

    std::cout << suma_producto(2, 10.5, 14.0, 1, 11.0) << endl; // El resultado seria: 46

    std::cout << suma_producto(-2, 0, 1, 0, 0) << endl; // El resultado seria: 0

}