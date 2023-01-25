#include <iostream>
using namespace std;


template<typename T = string>
T input(){
    string str;
    cin >> str;
    return str;
}

template<typename T = string>
T input(string str){
    T var;
    cout << str;
    cin >> var;
    return var;
}
