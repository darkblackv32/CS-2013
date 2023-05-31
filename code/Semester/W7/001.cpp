#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    vector<int> v = {1, 3 ,4, 5, 8};
    
    int i = 0;
    int j = v.size() - 1;
    while(i!=j){
        if(v[i] + v[j] == 10){
            cout << "YES" << endl;
            break;
        }
        else if(v[i] + v[j] < 10){
            i++;
        }
        else{
            j--;
        }
    }

    return 0;
}
