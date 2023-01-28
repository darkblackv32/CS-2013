#include "p8.h"

int main() {

    cout << boolalpha << are_same<int>() << endl; // true
    cout << boolalpha << are_same<int, char>() << endl; // false
    cout << boolalpha << are_same<int, char, double, int>() << endl; // true
    cout << boolalpha << are_same<vector<int>, vector<int> , vector<int>>() << endl; // true
    cout << boolalpha << are_same<int, const int, int&, int &&>() << endl; // false
    cout << boolalpha << are_same<int, int, int, int>() << endl; // true
    return 0;
}

