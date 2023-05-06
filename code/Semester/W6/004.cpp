#include <iostream>
#include <algorithm>
#include <list>

using namespace std;


void bubbleSort(auto begin, auto end){
    for (auto i = begin; i != end; i++)
        for (auto j = i; j != end; j++)
            if (*i > *j)
                swap(*i,*j);
}

int main(){
    list<int> l;
    generate_n(front_inserter(l), 20, [](){return rand()%100;});
    
    for_each(l.begin(), l.end(), [](int x){cout << x << " ";});
    cout << endl;

    bubbleSort(l.begin(), l.end());
    for_each(l.begin(), l.end(), [](int x){cout << x << " ";});
    cout << endl;

    return 0;
}