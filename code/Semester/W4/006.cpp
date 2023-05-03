#include <iostream>
#include <cmath>
using namespace std;

template<typename... Args>
double norma_2(Args... args){
    return pow((pow(args,2) + ...),0.5);
}

int main(){
    cout << norma_2(2,3);
}