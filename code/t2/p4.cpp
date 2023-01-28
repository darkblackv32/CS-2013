#include "p4.2.h"

void case_1(), case_2();

void case_1(){
    smart_ptr<int> sp1; // puntero inteligente no inicializado
    sp1 = make_smart_ptr<int>(10);
    
    cout << *sp1 << endl;   // Imprimiendo el contenido

    // puntero inteligente no inicializado
    smart_ptr<string> sp2 = make_smart_ptr<string>("Hola");
    cout << *sp2 << endl;
    
}

void case_2(){
    smart_ptr<point> sp1; // puntero inteligente no inicializado
    sp1 = make_smart_ptr<point>(20, 30);        // smart_ptr -> new point(20, 30)
    cout << *sp1 << endl;   // Imprimiendo el contenido

    smart_ptr<point> sp2 = make_smart_ptr<point>(10, 40); // puntero inteligente no inicializado
    cout << *sp2 << endl;
    // sp2->x = 5;
    cout << sp2->get_x() << endl;
    cout << sp2->get_y() << endl;
    
}

int main(){
    // case_1();
    case_2();

    return 0;
}