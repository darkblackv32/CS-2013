#include "p9.h"

void case_1(), case_2(), case_3(), case_4();

void case_1(){
    int arreglo[10];
    init_array(arreglo);    // Valor inicial 0
    for (const auto& i: arreglo)
        std::cout << i << " ";
    std::cout << std::endl;
    // output: 0 1 2 3 4 5 6 7 8 9
}

void case_2(){
    int arreglo[15];
    init_array(arreglo, 5); // Se puede configurar el valor inicial (5)
    for (const auto& i: arreglo)
        std::cout << i << " ";
    std::cout << std::endl;
    // output: 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
}

void case_3(){
    float arreglo[14];
    init_array(arreglo, 1, 3);  // Se puede configurar el valor inicial (1) y 
                                // el paso (3)
    for (const auto& i: arreglo)
        std::cout << i << " ";
    std::cout << std::endl;
    // output: 1 4 7 10 13 16 19 22 25 28 31 34 37 40
}

void case_4(){

    double arreglo[] {0, 0, 0, 4, 5, 6};
    init_array(arreglo, 2, 8, 2);   // Se puede configurar el valor inicial (2)
                                    // valor siguiente al final (8) y 
                                    // el paso (2)
    for (const auto& i: arreglo)
        std::cout << i << " ";
    std::cout << std::endl;
    // output: 2 4 6 4 5 6

}




int main(){
    case_1();
    case_2();
    // case_3();
}