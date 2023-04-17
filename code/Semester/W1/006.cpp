#include <bits/stdc++.h>
using namespace std;


class Dados{

private:
    int *ptr = nullptr;
    int can;

public:
    Dados(int n){
        can = n;
    }

    Dados(Dados&& other){

        if(other.ptr != nullptr){
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        else
            this->ptr = nullptr;
        
        if(other.can){
            can = other.can;
            other.can = 0;
        }
        else
            this->can = 0;
    }

    Dados(Dados& other){
        can = other.can;
        ptr = other.ptr;
    }

  
    void lanzar(){
        ptr = new int[can];
        float ba = 0;
        for(int i = 0; i < can; ++i){
            ptr[i] =  1+rand()%(1-6);
            cout << ptr[i] << " ";
            ba += ptr[i];
        }
        
        ba = ba / can;
        cout << endl;
        cout << "Promedio : " << ba << endl;
        if(ba > 4 or ba == 4){
            cout << "Ganaste" << endl;
        }
        else{
            cout << "Perdiste" << endl;
        }
    }
    
    void mostrar(){
        for(int i = 0; i < can; ++i)
            cout << ptr[i] << " ";
        cout << endl;
    }

    ~Dados(){
        delete[] ptr;
    }
};


int main(){

    srand(time(NULL));

    int n;

    cout << "Ingresa la cantidad de dados: " << endl;
    cin >> n;

    Dados d1(n);

    d1.lanzar();

    d1.mostrar();

    Dados d2 = d1;

    d2.mostrar();

    Dados d3 = move(d2);

    d2.mostrar();

    d3.mostrar();

    
    return 0;
}

