#include <iostream>
using namespace std;

template<typename F, typename... T>
auto foo(F first, T... args) {
    return (first - ... - args);

}


int main(){
    cout << foo (2) << endl ; // resultado = 2
    cout << foo (1 ,12) << endl ; // resultado = 1 -12 = -11
    cout << foo (7 ,3 ,0.5 ,1 ,2) << endl ; // resultado = 0.5
}