#include <algorithm>
#include <array>
#include <deque>
#include <forward_list>
#include <iostream>
#include <list>
#include <numeric>
#include <random>
#include <vector>
using namespace std;

#define all(cont) begin(cont), end(cont)

/*
TEMPLATES
    funciones   U
    variables   X
    alias       auxiliar a los template de funciones(args)/clases(atributos/return type)
    clases      
*/
template<typename A = int>      // template argument by default
using adj_list = vector<vector<A>>;

template<
    template<typename, class> typename container,
    typename T
>
void PRINT(container<T, allocator<T>>& cont) { cout<<"[ "; for (auto el : cont) cout << el << " "; cout<<"]"; }

// ! TEMPLATE ARGUMENT

// * TEMPLATE TYPE ARGUMENTS | TEMPLATE-TEMPLATE

template<
    template<typename, class> typename container,
    typename T
>
using it_cont = typename container<T, allocator<T>>::iterator;

template<
    template<typename, class> typename container,
    typename T
>
it_cont<container, T> 
min_element(
    container<T, allocator<T>>& cont
)
{
    printf("  %s\n", __PRETTY_FUNCTION__);
    it_cont<container, T> current = cont.begin(), en = cont.end();
    it_cont<container, T> min_it = current;
    while (current != en)
    {
        if (*current < *min_it)
            min_it = current;
        current = next(current);        // current++;
    }
    return min_it;
}

template<template<class, class> class T = std::vector, class V=int>
auto get_container(){ return T<V, std::allocator<V>>(); }

// * TYPE ARGUMENT -> garbage collector
template<typename X>
using itv = typename vector<X>::iterator;

template<typename T>
itv<T> min_element(vector<T>& cont)
{
    printf("  %s\n", __PRETTY_FUNCTION__);
    itv<T> current = cont.begin(), en = cont.end();
    itv<T> min_it = current;
    while (current != en)
    {
        if (*current < *min_it)
            min_it = current;
        current++;
    }
    return min_it;
}

// * NON-TYPE ARGUMENT
template<typename T, size_t N>
T* min_element(std::array<T, N>& arr)
{   
    printf("  %s\n", __PRETTY_FUNCTION__);
    // 1e6 -> 1e12 | buscar n lg2 n
    T* min = arr.begin();
    for (int i = 0; i < N; i++)     // iterar sobre los indices (posiciones)
        if (arr[i] < *min)
            min = next(begin(arr), i);     // obtener el i-esimo iteador -> a partir del begin(arr), realizas i hops y devuelves ese iterador
    // 1 + 2 + 3 + 4 + 5 + .. + N = N*(N+1)/2
    return min;
}

void test0()
{
    std::random_device rd;
    std::mt19937 g(rd());

    int N = 5;
    adj_list<> graph = adj_list<>(N, vector<int>());
    vector<int> v(15);
    iota(all(v), 'A');       // iota
    // PRINT(v);   cout<<endl;
    shuffle(begin(v), end(v), g);
    PRINT(v);   cout<<endl;

    vector<int>::iterator it_min = std::min_element(all(v));
    cout<<*it_min<<" -> "<< std::distance(begin(v), it_min)<<" hops from begin\n";
    cout<<"---------------------------------\n";
    auto min = ::min_element(v);
    cout<<*min<<" -> "<< std::distance(begin(v), min)<<" hops from begin\n";

    std::array<int, 5> arr = {50, 70, 45, 22, 72};;
    int* min_arr = ::min_element(arr);
    cout<<*min_arr<<endl;
}

void test1()
{

    std::random_device rd;
    std::mt19937 g(rd());
 
    vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    list<size_t> ls(10);
    std::iota(all(ls), 10);

    deque<long long> dq;
    copy(all(ls), std::front_inserter(dq));     // ? std::copy

    PRINT(vec);    cout<<endl;
    PRINT(ls);    cout<<endl;
    PRINT(dq);    cout<<endl;
    
    std::shuffle(all(vec), g);
    std::shuffle(all(dq), g);
    // std::shuffle(all(ls), g);

    auto itv = ::min_element(vec);
    auto itls = ::min_element(ls);      // iterador del menor elemento en std::list ls
    auto itdq = ::min_element(dq);

    PRINT(vec);    cout<<endl;
    PRINT(ls);    cout<<endl;
    PRINT(dq);    cout<<endl;

    auto pos = std::distance(begin(vec), itv);
    cout<< *itv <<" "<< vec[pos] <<endl;
    // composicion de funciones f(g(x)) | y = g(x), f(y) => f(g(x))
    cout<< *itls <<" "<< *next(
        begin(ls), 
        distance(begin(ls), itls)
    ) <<endl;            // iterator std::next(source_iterator, hops) -> realiza los saltos desde source_iterator y te devuelve el iterador despues de realizarlo
    
    cout<< *itdq <<" "<< dq[distance(begin(dq), itdq)] <<endl;
    // ? std::prev, std::advance
}

// ? VARIADIC TEMPLATES
/*
    https://preshing.com/20210315/how-cpp-resolves-a-function-call/
    https://en.cppreference.com/w/cpp/language/parameter_pack
    https://www.modernescpp.com/index.php/types-non-types-and-templates-as-template-parameters
    
? FOLD EXPRESSION
    https://www.modernescpp.com/index.php/from-variadic-templates-to-fold-expressions
    https://en.cppreference.com/w/cpp/language/fold
    https://mainfunda.com/fold-expressions-in-cpp17/
    https://www.fluentcpp.com/2021/03/12/cpp-fold-expressions/
    https://www.codingame.com/playgrounds/2205/7-features-of-c17-that-will-simplify-your-code/fold-expressions

1) Unary right fold 
    (E op ...) becomes (E1 op (... op (EN-1 op EN)))
2) Unary left fold 
    (... op E) becomes (((E1 op E2) op ...) op EN)
3) Binary right fold 
    (E op ... op I) becomes (E1 op (... op (EN−1 op (EN op I))))
4) Binary left fold 
    (I op ... op E) becomes ((((I op E1) op E2) op ...) op EN)

    https://stackoverflow.com/questions/32848107/c-variadic-template-iterate-vector-and-compare-elements
*/

auto sum(){ return 0; }

template<typename... pack, typename first>
auto sum(first F, pack... P)
{
    // * USE RECURSION
    // printf("  %s\n", __PRETTY_FUNCTION__);
    // cout<<" "<<sizeof...(P)<<"\n";       // tama;o del pack de parametros
    // auto res = F + sum(P...);
    // return res;       // P... significa desempacar los parametros

    // * FOLD EXPRESSION
    return (P + ...);
}


int main()
{
    // test0();
    // test1();
    cout<<sum(1, 2.5, 3LL, 4, (unsigned)5);
    return 0;
}
