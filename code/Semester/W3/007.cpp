#include <iostream>

using namespace std;

template<int n = 2>
class Polinomio{
    public:
    void print(){
        for(int i=0; i<n + 1; i++){
            cout << rand() % 10;
            if (i < n){
                cout << "x^" << (n-i);
                cout << " + ";
            }
        }
        cout << endl;
    }
};

int main(){
    Polinomio<4> pol1;
    pol1.print();       // Resultado: 3x^4 + 6x^3 + 7x^2 + 5x^1 + 3

    Polinomio pol2;
    pol2.print();       // Resultado: 5x^2 + 6x^1 + 2
}
