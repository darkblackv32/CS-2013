#include <algorithm> // max_element
#include <iostream>
#include <iterator>  // distance
#include <string>
#include <vector>
using namespace std;

template<typename T>
T max(vector<T> v){
    T max = v[0];
    for (int i = 0 ; i < v.size(); i++)
    {
        if(v[i] > max)
            max = v[i];
    }
    return max;
}

template<>
string max(vector<string> v){
    string max = v[0];
    for (int i = 0 ; i < v.size(); i++)
    {
        if(v[i].length() > max.length())
            max = v[i];
    }
    return max;    
}
    
int main() {
    vector<int> v1 = {2,4,6,12,54,134,2,54,21};
    vector<string> v2 = {"holaede","e"," ererrerererer","Dea"};
    cout << max(v1);
    cout << max(v2);
    return 0;
}   