#include <iostream>
#include <list>

using namespace std;

template<typename X>
std::ostream& operator<<(std::ostream& os, const std::list<X>& list)
{
    for (auto &i : list)
        os << " " << i;
    
    cout << endl;
    return os;
}

template<typename T>
void partir(std::list<T> &lista_origen, T pivote, std::list<T>& izquierda, std::list<T>& derecha) {
    //? points to the first element in the original list
    auto iter = lista_origen.begin();
    //? while the element is no equal as the last element in the or. list
    while (iter != lista_origen.end()) {
        if (*iter >= pivote) {
            izquierda.splice(izquierda.end(), lista_origen, iter++);
            //! std::list::split this function helps us to move elements from a list to another list
            //! in the first parameter we give the position of the element in the new list, in the second
            //! the source list, and the third one is just an iterator to iterate all the list
        }
        else {
            derecha.splice(derecha.end(), lista_origen, iter++);
        }
    }
}

int main() {

    list<int> l1 = {5,3,12,56,34,14}, l2, l3;
    
    cout << "l1 : "  << l1;

    partir(l1,12,l2,l3);

    cout << "l1 : "  << l1;
    cout << "l2 : "  << l2;
    cout << "l3 : "  << l3;
    

    

    return 0;
}

