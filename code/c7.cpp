/*
* std::containers
    * sequence
    ? associative
    ! complejidad y estructuras de datos
* std::iterators
    forward
    backward
    bidirectional
    random-access
* std::algorithms
    https://en.cppreference.com/w/cpp/algorithm
* functors, callables, lambda
*/

#include <bits/stdc++.h>
using namespace std;

/*
* TEMPLATE ARGUMENT TYPES
    TYPE       (T, V, typename K)
    NON-TYPE   (int, double, punto)
    ! TEMPLATE
    VARIADIC   (P...), Fold expressions
*/

// TEMPLATE TEMPLATE ARGUMENT

template<typename K, typename V>
class par
{
    K first;
    V second;
public:
    par() = default;
    par(K f, V s): first{f}, second{s}{};
};

template<
    template<typename K, typename V> class TT,         // typename...
    typename A, typename B       // typename... P
>
void func1(TT<A, B> something){
    cout << __PRETTY_FUNCTION__ <<endl;
}

template<
    template<typename, typename> class T = std::vector, 
    class V = int
>        // <> template parameter list
auto get_container()    // function parameter list
{
    cout << __PRETTY_FUNCTION__ <<endl;
    return T<V, std::allocator<V>>(); 
}

int main()
{
    // par<int, double> p1;
    // func1(p1);

    // vector<int> vec;
    // func1(vec);

    // vector<deque<double>> vv;
    // func1(vv);

    // ! std::map solo con variadic
    // map<int, int> mp1;
    // func1(mp1);

    // map<int, vector<int>> mp2;
    // func1(mp2);

    get_container<deque, double>();
    get_container<list, par<int, long long>>();
    get_container<vector, vector<int>>();
}

