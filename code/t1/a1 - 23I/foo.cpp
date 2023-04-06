#include "foo.h"

Matriz2D::Matriz2D(){
    // Constructor por defecto
    filas = 3;
    columnas = 3;
    ptr = new float*[3];
    for(int i = 0; i < 3; i++){
            ptr[i] = new float[3];
            for(int j = 0; j < 3; j++){
                ptr[i][j] = 0.2;
            }
    }
    
}

Matriz2D::Matriz2D(int n){
    // Constructor con un parametro
    filas = n;
    columnas = n;
    ptr = new float*[filas];
    for(int i = 0; i < filas; i ++){
        ptr[i] = new float[columnas];
        for(int j = 0; j < columnas; j++){
            ptr[i][j] = 0.3;
        }
    }
}

Matriz2D::Matriz2D(int n, int m){
    // Constructor con dos parametros
    filas = n;
    columnas = m;
    ptr = new float*[filas];
    for(int i = 0; i < filas; i++){
        ptr[i] = new float[columnas];
        for(int j = 0; j < columnas; j++){
            ptr[i][j] = 0.2;
        }
    }

}

Matriz2D::Matriz2D(const Matriz2D& m){
    // Constructor de copia
    filas = m.filas;
    columnas = m.columnas;
    ptr = new float*[filas];
    for(int i = 0; i < filas; i++){
        ptr[i] = new float[columnas];
        for(int j = 0; j < columnas; j++){
            ptr[i][j] = m.ptr[i][j];
        }
    }
}

Matriz2D::Matriz2D(Matriz2D&& m){
    // Constructor de movimiento
    filas = m.filas;
    columnas = m.columnas;
    ptr = new float*[filas];
    for(int i = 0; i < filas; i++){
        ptr[i] = new float[columnas];
        for(int j = 0; j < columnas; j++){
            ptr[i][j] = m.ptr[i][j];
        }
    }

    m.columnas = 0;
    m.filas = 0;
    m.ptr = nullptr;

}

Matriz2D t(Matriz2D& m){
    // Transpuesta de una matriz
    Matriz2D m2 (m.filas, m.columnas);
    for(int i = 0; i < m.filas; i++){
        for(int j = 0; j < m.columnas; j++){
            m2.ptr[i][j] = m.ptr[j][i];
        }
        cout << endl;
    }
    return m2;
}

std::ostream& operator<<(std::ostream& os, const Matriz2D& m){
    for(int i = 0; i < m.filas; i++){
        for(int j = 0; j < m.columnas; j++){
            os << m.ptr[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

Matriz2D operator+(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador +
    Matriz2D m3(m1.filas, m1.columnas);
    for(int i = 0; i < m1.filas; i++){
        for(int j = 0; j < m2.columnas; j++){
            m3.ptr[i][j] = m1.ptr[i][j] + m2.ptr[i][j]; 
        }
    }
    return m3;
}

Matriz2D operator-(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador -
    Matriz2D m3(m1.filas, m2.columnas);
    for(int i = 0; i < m1.filas; i++){
        for(int j = 0; j < m2.columnas; j++){
            m3.ptr[i][j] = m1.ptr[i][j] - m2.ptr[i][j];
        }
    }
    return m3;
}

Matriz2D operator*(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador *
    Matriz2D m3(m1.filas, m2.columnas);
    for(int i = 0; i < m1.filas; i++){
        for(int j = 0; j < m2.columnas; j++){
            m3.ptr[i][j] = m1.ptr[i][j] * m2.ptr[i][j];
        }
    }
    return m3;
}

Matriz2D operator+(const Matriz2D& m, float n){
    // Sobrecarga del operador +
    Matriz2D m2(m.filas, m.columnas);
    for(int i = 0; i < m.filas; i++){
        for(int j = 0; j < m.columnas; j++){
            m2.ptr[i][j] = m.ptr[i][j] + n;
        }
    }
    return m2;
    
}

Matriz2D operator-(const Matriz2D& m, float n){
    // Sobrecarga del operador -
    Matriz2D m2(m.filas, m.columnas);
    for(int i = 0; i < m.filas; i++){
        for(int j = 0; j < m.columnas; j++){
            m2.ptr[i][j] = m.ptr[i][j] - n;
        }
    }
    return m2;
}

Matriz2D operator*(const Matriz2D& m, float n){
    // Sobrecarga del operador *
    Matriz2D m2(m.filas, m.columnas);
    for(int i = 0; i < m.filas; i++){
        for(int j = 0; j < m.columnas; j++){
            m2.ptr[i][j] = m.ptr[i][j] * n;
        }
    }
    return m2;
}

Matriz2D operator/(const Matriz2D& m, float n){
    // Sobrecarga del operador /
    Matriz2D m2(m.filas, m.columnas);
    for(int i = 0; i < m.filas; i++){
        for(int j = 0; j < m.columnas; j++){
            m2.ptr[i][j] = m.ptr[i][j] / n;
        }
    }
    return m2;
}

float Matriz2D::get(int i, int j){
    return ptr[i][j];
}

int Matriz2D::getFilas(){
    return filas;
}

int Matriz2D::getColumnas(){
    return columnas;
}