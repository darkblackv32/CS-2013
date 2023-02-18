

/*
DS: Data Structures
    formas/construcciones algoritmicas para realizar operaciones CRUD
        CRUD(Create, Read, Update, Delete)
    Ejm:
        * Basics:
            Array
                Circular Array
            Linked List
                coleccion de nodos conectados
                nodos no son contiguos
                    Simple Forward
                    Circular Simple
                    Doubly 
                    Circular Doubly
            Grafo
                tupla (V, E) donde V es el conjunto de Vertices y E el conjunto de Edges(aristas)

                Arbol/Tree
                    grafo conexo y sin ciclos

                    Binary Tree -> 
                    BST -> 

                    Arbol autobalanceables
                        AVL
                        RedBlack
                Disjoint Set Union
                
            <algo> * lg(N)
        
        * Specifics:
            Problemas de Range Query
                [a ..... x]  -> [b ... d]
                Sqrt-Decomposition
                Segment Tree
*/


#include <bits/stdc++.h>
using namespace std;

void associative_containers()
{
        set<int> st = {90, 50, 30, 20, 10, 40, 80, 70, 60, 60};
    for (auto& s: st)
        cout << s << " ";
    cout<<endl;

    multiset<int> mst = {90, 50, 30, 20, 10, 40, 80, 70, 60, 60};
    for (auto& s : mst)
        cout << s << " ";
    cout<<endl;

    // []
    cout<< *next(begin(st), 2) << endl;

    // std::lower_bound | std::upper_bound -> versiones de la BinarySearch
    map<int, vector<int>> mp;

    // * Dado un arreglo de N elementos, responder cual es el numero de ocurrencias de cada elemento en el array
    // [1, 1e6, 2348, 2348, 80, 523423, 80, 523423, 1, 1, 50, 80]
    // 1: 3, 1e6: 1, 80: 3, 2348: 2, 523423: 2
    // por cada elemento cuentas sus ocurrencias linealmente -> cada elemento solo se encuentre 1 vez en todo el array
    // n*n

    // [1, 1e6, 2348, 2348, 80, 523423, 80, 523423, 1, 1, 50, 80]
    // [x, 1e6, 2348, 2348, 80, 523423, 80, 523423, x, x, 50, 80]
    // [x, 1e6,   x,   x, 80, 523423, 80, 523423, x, x, 50, 80]
    // [x, 1e6,   x,   x, x, 523423, x, 523423, x, x, 50, x]        O(N^2) runtime, O(1) memoria

    vector<int> v = {1, int(1e6), 2348, 2348, 80, 523423, 80, 523423, 1, 1, 50, 80, int(1e9)};

    cout<<v.size()<<endl;
    map<int, int> fmap;
    for (const int& el : v)     // N = numero de elementos del vector
    {
        fmap[el] += 1;            // lg(M), M = numero de nodos en el map (va creciendo)   -> lg(0) + lg(1) + ... lg(N-1) = ?
        for (auto& [k, v] : fmap)
            cout << " ("<<k << ": " << v << ") ";
        cout<<endl<<endl;
    }   // O(N*lg(N)) | M(N) -> 
    
    map<
        int, 
        map<double, 
            vector<pair<int, tuple<size_t, string, float>>>
        >
    > complex_map;
    
    // porque no usar array estatico? -> arr[i] = numero de ocurrencias del elemento i
    // arr[1] = 3
    // arr[1e6] = 1  max(v) casillas   O(N) runtime, O(max(v)) memoria
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
    cout<<level<<endl;

    if (lt.size() == 1 or lt.size() == 0)
        return lt;
    
    list<Y> lt2, lt3;
    auto iter = lt.begin();
    partir(lt, *iter, lt2, lt3);
    cout<<"\t"<<lt;
    cout<<"\t"<<lt2;
    cout<<"\t"<<lt3;

    ordenar(lt2, level+1);
    ordenar(lt3, level+1);
    

    lt.splice(lt.begin(), lt2);       // menores
    lt.splice(lt.end(), lt3);     // mayores

    return lt;
}


int main() {
    // list<int> l1 = {5,3,12,56,34,14}, l2, l3, l4;
    
    // cout << "l1 : "  << l1;

    // partir(l1,12,l2,l3);

    // cout << "l1 : "  << l1;
    // cout << "l2 : "  << l2;
    // cout << "l3 : "  << l3;

    list<int> l4;
    l4 = {5,4,17,1,67,14};
    ordenar(l4);        // * version del QuickSort

    cout << "respuesta: " << l4;

    return 0;
}