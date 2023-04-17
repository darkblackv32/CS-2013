#include <iostream>
using namespace std;

template<typename T>
T sum(T x, T n){
    float ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += (i * x);
        //! cout << i << "*" << endl; el real debug 
    }
    ans+=1;
    return ans;
}

int main(){

    // x n 
    cout << sum(5.7,3.9) << endl;

    return 0;
}