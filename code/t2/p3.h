#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include <array>
#include <forward_list>
using namespace std;

template<class T = int>
    auto sumarizar(T it_1, T it_2, double beg){
        // auto sum = beg;
        // * for
        // for(T it = it_1; it != it_2; ++it){
        //     sum += *it;
        // }
        // * while
        while (it_1 != it_2)
        {
            beg += *it_1++;
            // it_1 = next(it_1);
        }
        return beg;
        // while (it_1 != it_2) beg += *it_1++; return beg;
    }
