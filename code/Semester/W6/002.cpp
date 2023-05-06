#include <iostream>
#include <algorithm>
#include <iterator>
#include <forward_list>

using namespace std;

bool no_prime(int x){
    for(int i = 2; i < x; i++){
        if(x%i == 0){
            return true;
        }
    }
    return false;
}
int main(){

    srand((unsigned) time(NULL));

    forward_list<int> fl(100);

    generate(fl.begin(), fl.end(), [](){return rand()%100;});

    for_each(fl.begin(), fl.end(), [](int i){cout << i << " ";});

    cout << '\n';

    // to get the size of a fl
    cout << distance(fl.begin(), fl.end()) << '\n';

    fl.remove_if(no_prime);

    for_each(fl.begin(), fl.end(), [](int i){cout << i << " ";});
    cout << endl;

    cout << "fl size : " << distance(fl.begin(), fl.end()) << '\n';


    return 0;
}