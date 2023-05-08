#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void bubbleSort(vector<int>& A) {
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    int n = A.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                swap(A[j], A[j + 1]);
            }
        }
    }
}

int main(){

    srand((unsigned) time(NULL));

    vector<int> vec(20);

    generate(vec.begin(), vec.end(), [](){return rand()%100;});

    cout << "Before sorting: ";
    for_each(vec.begin(), vec.end(), [](int i){cout << i << " ";});

    bubbleSort(vec);

    cout << '\n' << "After sorting: ";

    for_each(vec.begin(), vec.end(), [](int i){cout << i << " ";});

    cout << '\n';

    return 0;
}