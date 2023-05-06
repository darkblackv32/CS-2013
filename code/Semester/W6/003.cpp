#include <iostream>
#include <algorithm>
#include <iterator>
#include <forward_list>
using namespace std;

auto append(forward_list<int> &fl, int x){
    auto it = fl.begin();
    while(next(it) != fl.end())
        it++;
    fl.insert_after(it, x);
}



int main(){

    srand((unsigned) time(NULL));

    forward_list<int> fl(10);
    
    generate(fl.begin(), fl.end(), [](){return rand()%100;});

    for_each(fl.begin(), fl.end(), [](int i){cout << i << " ";});

    append(fl, 10);

    cout << endl;
    for_each(fl.begin(), fl.end(), [](int i){cout << i << " ";});


    return 0;
}