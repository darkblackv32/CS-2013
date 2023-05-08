#include <iostream>
#include <set>
#include <algorithm>
#include <list>
using namespace std;


bool no_prime(int x){
    if(x == 0 || x == 1){
        return true;
    }

    for(int i = 2; i < x; i++){
        if(x%i == 0){
            return true;
        }
    }
    return false;
}


int main(){

    srand((unsigned) time(NULL));

    list<int> l1;
    set<int> s1;

    generate_n(inserter(l1, l1.begin()), 100, [](){return rand()%20;});

    // for_each(l1.begin(), l1.end(), [](int i){cout << i << " ";});

    l1.remove_if(no_prime);

    cout << '\n' << "list: " << endl;
    for_each(l1.begin(), l1.end(), [](int i){cout << i << " ";});

    for (const auto& i : l1) {
        s1.insert(i);
    }

    cout << '\n' << "set: " << endl;
    for_each(s1.begin(), s1.end(), [](int i){cout << i << " ";});

    return 0;   
}