#include <iostream>
#include <list>
#include <algorithm>
#include <random>

using namespace std; 


template<typename T>
std::list<T> gen_list(){
    list<T> lt;
    mt19937 generator(std::random_device{}());  
    uniform_int_distribution<T> distribution(1, 10000000);
    for(int i = 0; i < 100; i++){
      lt.push_back(distribution(generator));
  }
  return lt; 
} 


template<typename X>
ostream& operator<<(ostream& os, const list<X>& list)
{
    for (auto &i : list)
        os << " " << i;
    
    cout << endl;
    return os;
}

template<typename T>
void partir(list<T> &lista_origen, T pivote, list<T>& izquierda, list<T>& derecha) {
    //? points to the first element in the original list
    auto iter = lista_origen.begin();
    //? while the element is no equal as the last element in the or. list
    bool flag = false;
    while (iter != lista_origen.end()) {
        if (*iter < pivote) {
            izquierda.splice(izquierda.end(), lista_origen, iter++);
            //! std::list::split | this function helps us to move elements from a list to another list
            //! in the first parameter we give the position of the element in the new list, in the second
            //! the source list, and the third one is just an iterator to iterate all the list
        }
        else if (*iter > pivote) {
            derecha.splice(derecha.end(), lista_origen, iter++);
        }
        else
        {
            flag = true;
            iter++;
        }
    }
    if (flag)
    {
        derecha.push_back(pivote);
        lista_origen.pop_back();
    }
        
}

template<typename Y>
list<Y> ordenar(list<Y> &lt, int level = 1) {
    // if (level == 8)     // ponerle limite a la recursion
    //     return lt;
    // cout<<level<<endl;

    if (lt.size() == 1 or lt.size() == 0)
        return lt;
    
    list<Y> lt2, lt3;
    auto iter = lt.begin();
    partir(lt, *iter, lt2, lt3);
    // cout<<"\t"<<lt;
    // cout<<"\t"<<lt2;
    // cout<<"\t"<<lt3;

    ordenar(lt2, level+1);
    ordenar(lt3, level+1);
    

    lt.splice(lt.begin(), lt2);       // menores
    lt.splice(lt.end(), lt3);     // mayores

    return lt;
}


int main() {

    // part 001

    list<int> l1 = {5,3,12,56,34,14}, l2, l3, l4;
    
    cout << "l1 : "  << l1;

    partir(l1,12,l2,l3);

    cout << "l1 : "  << l1;
    cout << "l2 : "  << l2;
    cout << "l3 : "  << l3;

    // part 002 

    list<int> l5;
    l5 = {5,4,17,1,67,14};
    ordenar(l5);        // * version del QuickSort

    cout << "answer: " << l5;

    // part 003

    list<int> lt1 = gen_list<int>(), lt2;

    // using sort function
    lt1.sort();

    // using "ordenar" function

    lt2 = ordenar(lt1);

    if(lt1 == lt2){
        cout << "exactly identical"<<'\n';
    }
    else{
        cout << "not identical"<<'\n';
    }
    
    cout << lt1;
    cout << endl;
    cout << lt2;

    return 0;
}