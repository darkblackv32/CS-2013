#include <iostream>
#include <vector>
using namespace std;

template<typename T>
ostream& operator << (ostream& os, vector<T> &vec){
    for(int i = 0; i < vec.size(); i++){
        os << vec[i] << " ";
    }
    return os;
}

void ran_num(vector<int>& vec){
    srand((unsigned int)time(NULL)); 
    for (int i = 0; i < 100; i++)
    {   
        vec[i] = rand() % 100; 
    }
}

int max(vector<int>& vec){
    int max = 0;
    for (int i = 0; i < vec.size(); i++)
    {   
        if(vec[i] > max)
            max = vec[i];
    }
    return max;
}

float prom(vector<int>& vec){
    float prom = 0;
    for (int i = 0; i < vec.size(); i++)
    {   
        prom += vec[i];
    }
    return prom/100;
}

int main(){

    vector<int>v(100);

    ran_num(v);
    cout << max(v) << endl;
    cout << prom(v) << endl;
    cout << v;

}