#include <iostream>
using namespace std;

template<class T>
T Max(T a, T b){
    return a > b ? a : b;
}



template<class T, typename... Args>
auto Max(T a, T b, Args... args){
    return Max(Max(a,b),args...);
}


int main(){

    cout << Max(1,2,3,4,5,6,7,8,9,10) << endl;

    return 0;
}
