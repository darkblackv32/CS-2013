#include <iostream>
using namespace std;

// * overload, template parameter default
// template<typename T = string>
// T input(){
//     string str;
//     cin >> str;
//     return str;
// }

// template<typename T = string>
// T input(string str){
//     T var;
//     cout << str;
//     cin >> var;
//     return var;
// }
// * overload, template parameter default, function parameter default
template<typename T = string>
T input(string str=""){
    T var;
    cout << str;
    cin >> var;
    return var;
}