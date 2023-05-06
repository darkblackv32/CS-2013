#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


int f(){
    
    int i = rand()%100;
    return i; 
}

auto pr(){

}

int main(){

    srand((unsigned) time(NULL));
    
    vector<int> v(10);

    // generate(v.begin(), v.end(), f);
    generate(v.begin(), v.end(), [](){return rand()%100;});

    // for(auto i = v.begin(); i != v.end(); i++){
    //     cout << *i << " ";
    // }

    for_each(v.begin(), v.end(), [](int i){cout << i << " ";});

    cout << '\n';
    cout << "Max element : " << *max_element(v.begin(), v.end());
    cout << '\n';

    auto prom = 0.0;

    transform(v.begin(), v.end(), v.begin(), [](int i){return i+i;});
    
    float promedio = accumulate(v.begin(), v.end(), 0.0) / v.size();

    cout << "Avg : " << promedio << '\n';
    return 0;
}