#include <iostream>
#include <iomanip>
using namespace std;

template<int n = 2, typename T = int>
class Polinomio
{
private:
    /* data */
public:
    Polinomio() = default;
    ~Polinomio(){};
    void print(){
        for(int i=0; i<n + 1; i++){
            T num = rand() % 1001 - 500;
                if (num > 0 && i > 0)
                    cout << " + ";
                cout << setprecision(2);
                cout << num / 100 ;
                if (i < n){
                    cout << " x^" << (n-i);
                }   
        }
        cout << endl;
    }
};


int main(){

    srand(time(NULL));
    Polinomio<3, float> pol1;
    pol1.print();    

    Polinomio<4> pol2;
    pol2.print();      

    Polinomio pol3;
    pol3.print();

    return 0;
}