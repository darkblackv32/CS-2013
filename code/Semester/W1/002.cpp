#include <bits/stdc++.h>
using namespace std;

class Matriz2D
{
private:
    int **matriz = nullptr;
    int cols;
    int rows;
    friend ostream &print(ostream &os, const Matriz2D &matriz);
public:


    Matriz2D(vector<int> v , int k) : cols(k){
        int n = v.size();
        rows = n;
        matriz = new int*[rows];
        for(int i = 0; i < rows; i++){
            matriz[i] = new int[cols];
            for(int j = 0; j < cols; j++){
                matriz[i][j] = v[i];
            }
        }

    }
    Matriz2D() : rows(3), cols(3){; 
        matriz = new int*[rows];
        for(int i = 0; i < rows; i++){
            matriz[i] = new int[cols];
            for(int j = 0; j < cols; j++){
                matriz[i][j] = 1+rand()%(1-9);
            }
        }
    }


    Matriz2D(int n, int m) : rows(n), cols(m){; 
        matriz = new int*[rows];
        for(int i = 0; i < rows; i++){
            matriz[i] = new int[cols];
            for(int j = 0; j < cols; j++){
                matriz[i][j] = 1+rand()%(1-9);
            }
        }
    }


    Matriz2D(int a) {
        rows = a;
        cols = a;
        matriz = new int*[rows];
        for(int i = 0; i < a; i++){
            matriz[i] = new int[cols];
            for(int j = 0; j < a; j++){
                matriz[i][j] = rand()%9;
            }
        }
    }

    ~Matriz2D(){
        for(int i = 0; i < rows; i++)
            delete[] matriz[i];
        matriz = nullptr;
        
    };
};

ostream &print(ostream &os, const Matriz2D &matriz){
    for(int i = 0; i < matriz.rows; i++){
        for(int j = 0; j < matriz.cols; j++){
            os << matriz.matriz[i][j] << " ";
                    }
        os << endl;
    }
    return os;
}

int main(){

    vector<int> v1 = {1, 2, 3};

    Matriz2D m1(7);

    print(cout, m1);

    

    return 0; 

}