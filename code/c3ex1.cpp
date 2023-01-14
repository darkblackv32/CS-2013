#include "ex1.h"
using namespace library;
#define pb push_back     // MACRO


void ex1(), ex2(), references();


int main(){
    // ex1();
    // references();
    ex2();
}


void ex1(){

    book b1;

    cout << b1;

    book* b2 = new book("The Tin Drum", "Gunter Grass");
    

    cout << *b2;

    pair<string, string> pair("George Orwell", "1984");

    book* b3 = new book(pair);

    cout << *b3;    

    book* b4 = new book(*b3), b5 = *b4; // podemos usar el = sin haberlo sobrecargado

    cout << "b4 ----->" << *b4;
    cout << "b5 ----->" << b5;

    // book* b6= new book("Brave's New World", "Aldous Huxley");

    book b7;

    b7 = *b2; // COPYT ASSINGMENT OPERATOR

    cout << b7;    
}

void references(){  
    book b0; //* lvalue : tiene asignada memoria 
    //* REFERENCIA LVALUE
    book& lref = b0; // una referencia es solo un nombre alternativo

    // book& lref_error = book("Mario Benedetti", "La Tregua");

    //* REFERENCIA A RVALUE
    book&& lref_error = book("Mario Benedetti", "La Tregua");
    // una referencia rvalue es un nombre alternativo (una referencia) a una variable lvalue
    // es decir, una variable que tiene asignado un espacio de memoria
    // la ventaja de los rvalue es que puedes mover sus datos a un lvalue (mover data de un rvalue a un lvalue)
    // el move aprovecha los rvalue para pasar la data de ahi hacia un objeto real (lvalue)
}

void ex2(){
    vector<book> books;
    books.pb(book("Haruki Murakami", "Kafka On The Shore")); // lo de adentro es un rvalue
    cout<<books[0]<<endl;

    cout<<books.size()<<" "<<books.capacity()<<endl;
    books.pb(book("Stephen Hawking", "Theory of Everything"));
    cout<<endl;
    cout<<books.size()<<" "<<books.capacity()<<endl;
    books.pb(book("Gabriel Garcia Marquez", "Cien años de soledad"));
    cout<<endl;
    cout<<books.size()<<" "<<books.capacity()<<endl;
    books.pb(book("Mario Vargas Llosa", "El sueño del Celta"));
    cout<<endl;
    cout<<books.size()<<" "<<books.capacity()<<endl;
    books.pb(book("Julio Cortazar", "Rayuela"));
    cout<<endl;
    cout<<books.size()<<" "<<books.capacity()<<endl;
    books.pb(book("Jules Verne", "El Faro del Fin del Mundo"));
    cout<<endl;
    cout<<books.size()<<" "<<books.capacity()<<endl;
    books.pb(book("Bram Stoker", "Dracula"));
    cout<<endl;
    cout<<books.size()<<" "<<books.capacity()<<endl;
    books.pb(book("Ray Bradbury", "Fahrenheit 451"));
    cout<<endl;

    /*recordar que los moves se dan cuando movemos cada elemento al vector, deja el lugar donde estaba vacio y llena el
    espacio de memoria del vector*/

    cout<<books[5]<<endl;
    books[5] = book("Jane Austen","Pride and Prejudice");        // * MOVE ASSIGNMENT (rvalue)
    cout<<books[5]<<endl;

    book b_ex;
    b_ex = book("Emily Brontë","Wuthering Heights");        // * MOVE ASSIGNMENT (rvalue)
    cout<<b_ex<<endl;
    

}