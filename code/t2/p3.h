#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include <array>
#include <forward_list>
using namespace std;

template<class T = int>
    auto sumarizar(T it_1, T it_2, double beg){
        auto sum = beg;
        for(T it = it_1; it != it_2; ++it){
            sum += *it;
        }
        return sum;
    }
