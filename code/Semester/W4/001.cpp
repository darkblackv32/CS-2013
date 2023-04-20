#include <iostream>
using namespace std;
template<class T>
T suma(T a, T b){
    return a +b;
}
template<class T1,class T2>
char suma(T1 a,T2 b){
    return a+b;
}

int main(){
    cout << suma(2, 1) << endl;
    cout << suma('z', 'j') << endl;
    cout << suma('A', 1) << endl;
    cout << suma(2, 'A') << endl;
    return 0;
}