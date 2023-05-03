#include <iostream>
using namespace std;



template <typename ...Args>
double media_armonica(Args... args){
    return (sizeof...(args)/ ((1.0/args) + ...));
}


int main(){
    cout << media_armonica(1,2,3,4,5);
}