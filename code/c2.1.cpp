#include "c2.1.h"
using namespace std;
// using namespace jj;

typedef unsigned long int unli;
typedef vector<unli> vuli;
typedef vector<float> vflo;
typedef list<int> lint;
typedef deque<int> dint;

template<class T>
void PRINT_VEC(vector<T> &v) { cout << "[ "; for (auto el : v) cout << el << " "; cout << "]"; }

void namespace_amistad_clases(), referencias();

int main(){

    // namespace_amistad_clases();
    referencias();

}


void referencias(){
    
}


void namespace_amistad_clases(){
    
    vuli ejem {34LL, unli(1e6), unli(1e7 + 18), unli(23e9 + 98214)};
    // para ser negativo = 1e-6;
    PRINT_VEC(ejem);
    cout<<endl;

    // STL
    vflo vf1(6, 7.23);
    PRINT_VEC(vf1);
    cout<<endl;

    // NAMESPACE
    jj::vflo vf2(6, 7.29);
    cout<<vf2;
    cout<<endl;

    /*usando el namespace jj:: evitamos la ambiguedad, utilizando asi el tydef vflo (vector de floats)
     y la clase vflo (que con arrays imita a un vector float)*/

    // STL

    lint l1; // llfo = list<float>
    l1.emplace_back(5);
    l1.emplace_front(1e5);

    cout << "list = [ ";
    for (int n : l1)
        cout << n << " ";
    cout << "]\n";
    

    // NAMESPACE
    // trate de usar una lista y un set en vez de un deque, parece que su forma de imprimir no puede sobrecargarse TT :((((((
    // jj::lint l2;

    // cout << "list = [ ";
    // for (int n : l2)
    //     cout << n << " ";
    // cout << "]\n";

    // STL
    dint d1; // dint = deque<int>
    d1.emplace_back(78);
    d1.emplace_front(1e2);
    cout<<"deque: [ ";
        for(int i = 0; i < d1.size(); ++i)
            cout<<d1[i]<<" ";
        cout<<"]\n";

    // NAMESPACE

    jj::dint d2(8,5);
    d2[3] = 4;

    cout<<"deque2: [ ";
        // cout<<d2[9]; para mandar el error
        for(int i = 0; i < d2.sz(); ++i)
            cout<<d2[i]<<" ";
        cout<<"]\n";
    
    d2.copy_from_dint(vf2);

    cout<<"vf2 copy to d2 -> [ ";
    for(int i=0; i < d2.sz(); ++i)
        cout<<d2[i]<<" ";
    cout<<"]\n";
    
}