#include <iostream>
using namespace std;


auto suma_producto(){
    return 0;
}

template<typename F>
auto suma_producto(F first){
    return first;
}

template<typename... T, typename F, typename S>
auto suma_producto(F first, S second, T... args){
    return first * second + suma_producto(args...);
};