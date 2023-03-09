#include <iostream>
#include <random>
#include <vector>
using namespace std;

template<int n = 2>
class Polinomio{
private: 
    vector<int> coefficients;
public:

    
    
    friend ostream& operator <<(ostream& os, const Polinomio& pol){
    srand(time(NULL));
    Polinomio p;
    for(int i=0; i < n + 1; i++){
            p.coefficients.push_back(rand() % 100);
        }
    for(int i=0; i < n + 1; i++){
            
            cout << p.coefficients[i];
            if (i < n){
                cout << "x^" << (n-i);
                cout << " + ";
            }
        }
        cout << endl;
    return os;
    }

    void pr_vec(){
        for(int i=0; i < coefficients.size(); i++){
            cout << coefficients[i] << " ";
        }
        cout << endl;
    }
    // Polinomio operator+(const Polinomio& other) const {
    //     Polinomio result;
    //     for(int i=0; i < n + 1; i++){
    //         result.coefficients[i] = coefficients[i] + other.coefficients[i];
    //     }
        
    //     return result;
    // }
};



int main(){
    
    Polinomio<1> p1;
    cout << p1 << endl;

    Polinomio<1> p2;
    cout << p2 << endl;
}