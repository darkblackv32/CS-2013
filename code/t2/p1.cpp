#include "p1.h"

int main(){
    
    auto text = input();
    auto entero = input<int>("Ingrese un numero: ");
    auto real = input<double>("Ingrese un numero: ");
    std::cout << "El texto es: " << text << endl;
    std::cout << "El entero es: " << entero << endl;
    std::cout << "El real es: " << real << endl;

    return 0;
}