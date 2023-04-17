#include <iostream>
using namespace std;

template<typename T>
T swap_func(T a1, T a2){
    cout << "before : " << "x1 = " << a1 << ", x2 = " << a2 << endl;
    T temp = a1;
    a1 = a2;
    a2 = temp;
    cout << "after : " << "x1 = " << a1 << ", x2 = " << a2 << endl;
    return a1;
    
}



int main(){


    float x = 9.6;
    float y = 10.99;

    swap_func(x,y);

    return 0;
}