#include <iostream>
#include <list>
#include <vector>
#include<type_traits>
// variadic
using namespace std;

template<typename... Ts, typename T>        // ! el orden importa, la deduccion es de derecha a izq
constexpr int index_of(T var) {
    int index = -1;
    return index;
}

        