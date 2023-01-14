#include "c4.h"

/*
PROGRAMACION GENERICA
    Es como un POO
    Focus on the algorithms, forget data types.
        Data types are declared in the call(function, class object, ...)
    
    * void sort_vec(vector<int> vec), sort_vec(vector<double> vec);

    ADVANTAGES:
        reduce the size of source code
        reduce the casting (malo)
        focus on the implementation, forget data types

    DISADVANTAGES
*/

typedef long long ll;

void ejemplo_casting(), ejemplo_inlist(), ejemplo_my_pair(), ejemplo_templates();

// int max(int n1, int n2)
// { 
//     // OVERFLOW
//     cout<<n1<<" "<<n2<<endl;
//     return (n1>n2)? n1 : n2; 
// }

// auto max(ll a, int b)
// {
//     return (a>b)? a : b;
// }

void ejemplo_casting()
{
    ll large = 2147483647 + 1e4;
    int entero = INT_MAX;

    // cout<<LLONG_MAX<<" "<<LLONG_MIN<<endl;
    // cout<<INT_MIN<<endl;
    cout<<large<<" "<<entero<<endl;

    // ! UNDEFINED BEHAVIOUR -> warnings, syntax error

    // * accessing declarations of global scope
    // cout<<::max(large, entero)<<endl;
    
    // templates -> evitan el typecasting

    // casting explicito
    cout<<max(int(5LL), 4)<<endl;
    cout<<max(5LL, (ll)14)<<endl;

    // * 1. Los tipos deben ser incluidos en la lista de parametros de template
    cout<<max(5, 4)<<endl;
    // int const& std::max<int>(int const&, int const&)
    /*
    T = int
    const T& max( const T& a, const T& b );

    const int& max( const int&, const int&);
    */
    // 1. Los tipos deben ser incluidos en la lista de parametros de template
    cout<<max<long long>(5LL, 4)<<endl;
    /*
    long long const& std::max<long long>(long long const&, long long const&)
    */
    cout<<max<int>({5LL, 4, 16, 18000})<<endl;
    /*
    T max(std::initializer_list<T> ilist)
        T = int
    int std::max<int>(std::initializer_list<int>)
    */

    cout<<max("ab", "bc")<<endl;
}

/*
TEMPLATE RULES
    1. Los tipos deben ser incluidos en la lista de parametros de template
    2. La deduccion parte de la derecha a la izquierda
    3. La deduccion se detiene al momento de encontrar un tipo no deducible
*/

// * CLASS/STRUCT TEMPLATE
template<typename T1, typename T2>
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

void ejemplo_inlist()
{
    // ? words0 -> words 1 sola linea copy_from()
    std::vector<std::string> words1 {"the", "frogurt", "is", "also", "cursed"};
    std::list<string> words0 {"the", "frogurt", "is", "also", "cursed"};

    cout<<max({1, 2, 3, 4, 5, 10})<<endl;
    /*
    MEMBER vs. NON-MEMBER
        https://www.cs.uregina.ca/Links/class-info/210/Overloading/membervsregular.html
        1. A non-member function always appears outside of a class.
        2. Another difference between member functions and non-member functions is how they are called (or invoked) in the main routine (algorithm vs method) 
    */

    initializer_list<string> letras {"a", "b", "c", "d", "e", "f"};
    cout<<letras.size()<<endl;     // METODO -> MEMBER FUNCTIONS

    auto it = begin(letras);         // ALGORITMO -> std::begin
    auto it2 = letras.begin();       // METODO -> std::initializer_list<T>::begin
    cout<<*it<<" "<<*it2<<endl;

    auto itv = begin(words1);       // words1.begin()
    // scope resolution operator ::

    initializer_list<int>::value_type i = 5;        // ==>  int i = 5
    /*
        _E = int
        typedef _E value_type
        typedef int value_type

        std::decltype
    */

    // * std::decltype
    ll jj = 1000;
    auto aa = jj;       // ll aa = jj;

    int v = 2147483647;
    auto vv = v + v;   // auto = int | deduce

    decltype(jj) ss = (decltype(jj))v + (decltype(jj))v;

    using tipo_j = decltype(jj);
    tipo_j sss = (tipo_j)v + (tipo_j)v;

    cout << vv << endl;
    cout << sss << endl;
    
    using T = int;
    using V = float;

    std::pair<T, V> p1;
    // cin>>p1.first>>p1.second;

    // * decltype(var) --> dame el tipo de la variable
    std::pair<T, V>::first_type f;           // T f;
    decltype(p1)::second_type s;        // V s;

    cin>>f>>s;

    p1.first = f;
    p1.second = s;
}

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
        decltype(p2) p3(1, 2);
        using tipo_p3 = decltype(p3);

        tipo_p3::first_type first_p2 = 6.8;
        tipo_p3::second_type second_p2 = 5.5;

        p2.swap(p3);

        cout<<" {"<<p2.first<<" "<<p2.second<<"}\n";
        cout<<" {"<<p3.first<<" "<<p3.second<<"}\n";

        decltype(p1) p4(0.2345342052345234534, 0);

        decltype(p1)::first_type almost_one = 0.9899999999;
        using tipo_2_p1 = decltype(p1)::second_type;

        tipo_2_p1 zero = 0;    // int zero = 0
        cout<<almost_one<<" "<<zero<<"\n";
    }
}

// ? SYNTAX ->  template<comma-separated-list-of-parameters>

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

// * ALIAS TEMPLATE
// representa la fam de initializer_list de diverso tipo
template<typename X=int>      // * default template parameter
using ilist = std::initializer_list<X>;

void ejemplo_template_arguments();

int main()
{
    // ejemplo_casting();
    // ejemplo_inlist();

    // ilist<double> numeros {1, 2, 3, 4, 5};
    
    // ilist<> enteros {10, 9, 8, 7};
    // ilist<>::iterator beg = enteros.begin();
    // for(; beg != enteros.end(); beg++)      // start, stop, step
    //     cout<<*beg<<" ";
    ejemplo_template_arguments();
    return 0;
}

/*
TEMPLATES   
    plantillas que representan una familia de ...
        funciones
        alias
        variables
        clases
        etc...
*/

// ! TEMPLATE TYPE ARGUMENTS -> https://www.modernescpp.com/index.php/types-non-types-and-templates-as-template-parameters
// * TEMPLATE-TEMPLATE ARGUMENTS

/*
template<template<class, class> class T = std::vector, class V=int>
T<V, std::allocator<V>> get_container(){ return T<V, std::allocator<V>>(); }
*/

template<template<class, class> class T = std::vector, class V=int>
auto get_container(){ return T<V, std::allocator<V>>(); }

// template<template<typename...> class T = std::vector, class V=int>
// T<V> get_container(){ return T<V>(); }           // ? this is open to crashed in compile time -> induction to variadic templates (cooming soon)

void ejemplo_template_arguments()
{
    /*
    TEMPLATE PARAMETER -> template parameter can be types, non-types, templates
    */
    
    // * TYPE ARGUMENTS


    // * NON-TYPE ARGUMENTS


    // * TEMPLATES
    auto vector_int = get_container();
    auto deque_int = get_container<std::deque, int>();
    auto fwdlist_double = get_container<std::forward_list, double>();

    // decltype(get_container<std::list, string>()) == std::list<string>
    decltype(get_container<std::list, string>()) list_str {"Merry", "Christmas", "&", "Happy", "New", "Year", to_string(2023)};
    // auto list_str = get_container<std::list, string>();
    // list_str = {"Merry", "Christmas", "&", "Happy", "New", "Year", to_string(2023)};
    for (const string& el : list_str)
        cout<<el<<" ";
    cout<<endl;
}

