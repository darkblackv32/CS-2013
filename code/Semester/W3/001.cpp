#include <iostream>
using namespace std;

template<typename T1, typename T2, typename T3>
T1 foo(T1 x, T2 y, T3& z){
    z = x / y;
    return x*y;
}

int main(){

    int a = 2;
    float b = 3;
    double c = 4;
    cout << foo(1, 1.2, c) << endl;
    cout << c << endl;

}