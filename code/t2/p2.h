#include <iostream>
#include <fstream>
#include <vector>
#include <list>
using namespace std;

template<typename T>
    auto print(T it_first, T it_second, ostream &os, string ad){
        for(T it = it_first; it != it_second; ++it){
            cout << *it << ad; 
        }
    };
