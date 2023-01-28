#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
using namespace std;

template<typename T>
auto print(T it_first, T it_second, ostream &os, string ad)     // void
{
    cout<<__PRETTY_FUNCTION__<<endl;
    for(T it = it_first; it != it_second; ++it)
    {   // O(n)
        os << *it;
        // if (distance(it, it_second) > 1)        // O(n) -> it_actual es distinto de uno anterior al ultimo
        //     os<<ad;
        if (next(it, 1) != it_second)               // O(1)
            os<<ad;
        // if (it != prev(it_second))                  // ! no todos los contenedores tienen el mismo tipo de iterador (bidirectional <-> , random [], forward -> ) SegFault
        //     os<<ad;
    }
    os<<endl;
    // return os;
    // * std::distance
    // (n + n-1 + n-2 + ... + 1) = n*(n+1)/2
    // c1 * n^2 <= n*(n+1)/2  <= c2 * n^2
    
    // * std::next | std::prev
    // (1 + 1 + .. + 1) = O(n)
    // 10 20 30 40 x
    // b           e 
    // 10-
    //    b        e
    //    20-
    //       b     e
    //       30-
    //           b e
    //           40
    // * std::next, std::advance, std::distance, std::prev
    
};
