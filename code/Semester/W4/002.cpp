#include <iostream>

using namespace std;

template<class T>
void suma(T m1, T m2, int filas, int colum){
    for (int i = 0; i < filas; i++){
        cout << "| ";
        for (int j = 0; j < colum; j++){
            std::cout.width(3);
            cout << m1[i][j] + m2[i][j] << " ";;
        }
        cout << "|" << endl;
    }
}

template<class T>
void suma(T m1, float s, int filas, int colum){
    for (int i = 0; i < filas; i++){
        cout << "| ";
        for (int j = 0; j < colum; j++){
            std::cout.width(3);
            cout << m1[i][j] + s << " ";;
        }
        cout << "|" << endl;
    }
}

int main(){
    int filas;
    int colum;

    cout << "Ingresar filas: ";
    cin >> filas;
    cout << "Ingresar columnas: ";
    cin >> colum;

    // Primera matriz
    // ================================
    float **m = new float *[filas];

    for (int i = 0; i < filas; i++)
        m[i] = new float[colum];


    for (int i = 0; i < filas; i++){
        for (int j = 0; j < colum; j++){
            m[i][j] = i * colum + j;
        }
    }

    // Segunda matriz
    // ================================
    float **r = new float *[filas];

    for (int i = 0; i < filas; i++)
        r[i] = new float[colum];


    for (int i = 0; i < filas; i++){
        for (int j = 0; j < colum; j++){
            r[i][j] = filas*colum - (i * colum + j);
        }
    }

    // Suma de dos matrices
    suma(m,r,filas,colum);

    // Scalar
    // ================================
    float s;
    cout << "Ingrese un escalar: ";
    cin >> s;

    // Suma de una matriz y un escalar
    suma(m,s,filas,colum);
    
    // Liberar cada fila
    for (int i = 0; i < filas; i++)
        delete [] m[i];

    // Liberar el array de punteros
    delete [] m;

    for (int i = 0; i < filas; i++)
        delete [] r[i];
    delete [] r;   

    return 0;
}