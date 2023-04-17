#include <iostream>
using namespace std;

template<typename T>
T bubble(T arr[], int n){
    int right = n-1;
    T temp = 0;
    int k;
    while (right > 0)
    {
        k = 0;
        for (size_t i = 0; i < right; i++)
        {
            if(arr[i+1] < arr[i]){
                temp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = temp;
                k = i;
            }
            right = k;
        }
        
    }
    // return arr;
}



int main(){

    char arr[5] = {'a', 'z', 'c', 'u', 'b'} ;

    int n = sizeof(arr) / sizeof(arr[0]);
    bubble(arr,n);

    for (size_t i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    
}