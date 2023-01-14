#include "c4.h"
typedef long long ll;

void casting_min(), initial_list(), ejemplo_my_pair(), ejemplo_template_arguments();

int min(int n1, int n2){

        cout<<n1<<" "<<n2<<endl;

    cout << "el min es: ";
    return (n1>n2)? n2 : n1; 
}

void casting_min(){

    ll loong = LONG_LONG_MAX; // 9223372036854775807
    int maxint = INT_MAX; // 2147483647

    // cout << loong << " " << maxint << endl;
    // cout << min(loong, maxint);
    // ! OVERFLOWWW
    // me dice que es min es -1, pero -1 no es loong, ni maxint 

    // todo ESTO LO PODEMOS SOLUCIONAR CON UN CASTING EXPLICITO 

    cout << min(loong, ll(maxint)); // FUNCIONA PORQUE EL MAX_INT tambien puede ser un LONG LONG
    // cout << min(int(loong), maxint); // ! FUNCIONARIA SI EL LOONG SERIA MENOR O IGUAL A INT_MAX
    

    // 1. Los tipos deben ser incluidos en la lista de parametros de template
    cout<<max<long long>(5LL, 4)<<endl; //todo TOMA A AMBOS COMO LL
    /*
    long long const& std::max<long long>(long long const&, long long const&)


    */
    cout<<min<int>({56, 1, 34, 10997}) << endl; //? ES UNA UNITIALIZER LIST A LA CUAL LE SACAMOS EL MIN
    /*
    T max(std::initializer_list<T> ilist)
        T = int
    int std::max<int>(std::initializer_list<int>)
    */

    cout<<max("zb", "bc")<<endl;

}

void initial_list(){

    using namespace std;

    // TODO : Initializer List Definition : a lightweight proxy object that provides access to an array of objects of type const T
    
    // ? words0 -> words 1 sola linea copy_from()

    std::vector<std::string> words1 {"the", "frogurt", "is", "also", "cursed"};
    std::list<string> words0 {"the", "frogurt", "is", "also", "cursed"};

    cout<<max({1, 2, 3, 4, 5, 10})<<endl;

    /*
    MEMBER vs. NON-MEMBER
        1. A non-member function always appears outside of a class.
        2. Another difference between member functions and non-member functions is how they are called 
        (or invoked) in the main routine (algorithm vs method) 
    */
    
    initializer_list<string> letras {"a", "b", "c", "d", "e", "f"};
    cout<<letras.size()<<endl;     // METODO -> MEMBER FUNCTIONS

    auto it = begin(letras);         // ALGORITMO -> std::begin
    auto it2 = letras.begin();       // METODO -> std::initializer_list<T>::begin
    cout<<*it<<" "<<*it2<<endl;

    auto itv = begin(words1);       // words1.begin()
    cout << *itv << endl;
    // scope resolution operator ::

    initializer_list<int>::value_type i = 5;        // ==>  int i = 5
    //? el int que declaramos al inicializar la lista se vuelve _E, por eso value_type tambien
    /*
        _E = int
        typedef _E value_type
        typedef int value_type
        std::decltype
    */

    // * std::decltype 

    //TODO: basicamente es el tipo del objeto

    ll jj = 1000;
    auto aa = jj;       // ll aa = jj;

    int v = 2147483647;
    auto vv = v + v;   // auto = int | deduce

    decltype(jj) ss = (decltype(jj))v + (decltype(jj))v; 
    //* traduciendo un poco la linea 98:
    //* estamos creando una nueva variable ss de mismo tipo que tiene jj que es ll, y le estamos
    //* asignando la suma de v + v, que son del tipo de jj que es ll (parece un casteo)

    using tipo_j = decltype(jj); //* le damos al tipo de la variable jj un alias llamado tipo_jj == ll
    tipo_j sss = (tipo_j)v + (tipo_j)v; //* nueva variable ll sss, suma v + v, ambos son tipos_j == ll 

    cout << vv << endl;
    cout << sss << endl;
    
    using T = int;
    using V = float;

    std::pair<T, V> p1;
    // cin>>p1.first>>p1.second;

    // * decltype(var) --> dame el tipo de la variable

    std::pair<T, V>::first_type f;           // T f;
    decltype(p1)::second_type s;        // V s;  //todo EL DECLTYPE NOS AYUDA A INGRESAR LOS TIPOS DEL PAIR
//*: declaramos s y f como variables asignandoles sus respectivos tipos usando sus member value types
//* que en este caso son dos
    
    cin>>f>>s;

    p1.first = f; // asignacion 
    p1.second = s; // asignacion
}

// * CLASS/STRUCT TEMPLATE
template<typename T1, typename T2> // se crea un struct que imita al pair container 
struct pair
{
    // ! REMEMBER: std::vector<int>::iterator ... what is this? this is a member type
    // MEMBER TYPES
    typedef T1 first_type;    // The type of the `first` member
    typedef T2 second_type;   // The type of the `second` member

    T1 first;
    T2 second;

    pair(T1 _f, T2 _s): first{_f}, second{_s}{};
};

void ejemplo_my_pair()
{
    // * CLASS TEMPLATE -> pair
    typedef int entero;

    ::pair<double, entero> p1(5.5, 7);
    cout<<" {"<<p1.first<<" "<<p1.second<<"}\n";
    // * Ctrl + click
    std::pair<int, float> p2(6.8, 5);
    cout<<" {"<<p2.first<<" "<<p2.second<<"}\n";

    {
        decltype(p2) p3(1, 2); //* p3 esta siendo declarado con el tipo de p2 <int, float>
        using tipo_p3 = decltype(p3); //* usamos el alias tipo_p3 para el tipo de p3 <int, float> 

        tipo_p3::first_type first_p2 = 6.8;  //* el first_type de tipo_p3 (int) es 6.8
        tipo_p3::second_type second_p2 = 5.5; //* el second_type de tipo_p3 (float) es 5.5

        p2.swap(p3); //? it swaps the values of the two variables

        cout<<" {"<<p2.first<<" "<<p2.second<<"}\n";
        cout<<" {"<<p3.first<<" "<<p3.second<<"}\n";

        decltype(p1) p4(0.2345342052345234534, 0); //* declaramos p4 con el tipo de p1 <double, int>

        decltype(p1)::first_type almost_one = 0.9899999999; //* declaramos el first_type del tipo p1 (double)
        using tipo_2_p1 = decltype(p1)::second_type; //* damos  un alias al second_type de p1 (int)

        tipo_2_p1 zero = 0;    // int zero = 0
        cout<<almost_one<<" "<<zero<<"\n";
    }
}



// * ALIAS TEMPLATE
// representa la fam de initializer_list de diverso tipo
template<typename X=int> //* DATA TYPE POR DEFECTO = INT      // * default template parameter
using ilist = std::initializer_list<X>; //? generamos un template para iniciar una initializer list
/*
TEMPLATES   
    plantillas que representan una familia de ...
        funciones
        alias
        variables
        clases
        etc...
*/

// * FUNCTION TEMPLATE
template<typename T/*T is the convention*/>
T maxi(T a, T b)
{
    /**
    the type parameter represents an arbitrary type that is determined by the caller when the caller calls the function
    you can use any type (fundamental, class) as long as it provides the operations that the template uses
    template/class are god (history)
    */
    return b < a ? a : b;
}

int main(){
    // casting_min();
    // initial_list();
    // ejemplo_my_pair();

    // ilist<double> numeros {1, 2, 3, 4, 5};

    // //? ES UN TEMPLATE DE ALIAS
    // ilist<> enteros {10, 9, 8, 7}; //* usamos el <> vacio para que tome  el data type por defecto
    // ilist<>::iterator beg = enteros.begin();
    // for(; beg != enteros.end(); beg++)      // start, stop, step
    //     cout<<*beg<<" ";                    //todo:  imprimir la initializer list desreferenciado su iterador 
    
    ejemplo_template_arguments();


    return 0;
}

// ! TEMPLATE TYPE ARGUMENTS -> https://www.modernescpp.com/index.php/types-non-types-and-templates-as-template-parameters
// * TEMPLATE-TEMPLATE ARGUMENTS

/*
template<template<class, class> class T = std::vector, class V=int>
T<V, std::allocator<V>> get_container(){ return T<V, std::allocator<V>>(); }
*/

template<template<class, class> class T = std::vector, class V=int> //? una clase es vector y la otra es int por defecto //! NOT SURE
auto get_container(){ return T<V, std::allocator<V>>(); }
//* de alguna manera el get_container regresa los valores dentro de un contenedor

// template<template<typename...> class T = std::vector, class V=int>
// T<V> get_container(){ return T<V>(); }           // ? this is open to crashed in compile time -> induction to variadic templates (cooming soon)

void ejemplo_template_arguments()
{
    /*
    TEMPLATE PARAMETER -> template parameter can be types, non-types, templates
    Template parameters can be types, non-types, and templates.
    */
    
    /* TYPE ARGUMENTS
        the most often used template parameters 
        e.g:
            std::vector<int> myVec;
            std::map<std::string, int> myMap;
    *\

    /* NON-TYPE ARGUMENTS
        Non-types can be a
            lvalue reference
            nullptr
            pointer
            enumerator
            integral type
    */


    // * TEMPLATES
    auto vector_int = get_container();
    auto deque_int = get_container<std::deque, int>();
    auto fwdlist_double = get_container<std::forward_list, double>();

    decltype(get_container<std::list, string>()) list_str {"Merry", "Christmas", "&", "Happy", "New", "Year", to_string(2023)};
    for (const string& el : list_str)
        cout<<el<<" ";
    cout<<endl;

    //todo : 267 ~ se declara a list_str como un get_container con tipos <list, string>, se le adjunta una lista y luego un string
    //! no logro comprender como reconocer a los 6 primero como una lista y no al ultimo
}

