#pragma once
#include <iostream>
using namespace std;

namespace utec{

    class matrix_t
    {
    private:
        int rows;
        int cols;
        int** mat = nullptr;
    public:
    
        matrix_t(const int _rows, const int _cols) : rows(_rows), cols(_cols){
            mat = new int*[_rows];
            for(int i = 0; i < _rows; i++){
                mat[i] = new int[_cols];
                for(int j = 0; j < _cols; j++){
                    mat[i][j] = 0;
                }
            }
        }

        int row_size(){return rows;}
        int col_size(){return cols;}

        ~matrix_t(){
        for(int i=0; i< rows; i++){
                delete [] mat[i];
            delete [] mat;
            mat = nullptr;
            break;}
        }

    friend ostream &operator<<(ostream &os, const matrix_t &m) {
        for (int i=0; i < m.rows; ++i) {
            for (int j=0; j < m.cols; ++j) {
                os << m.mat[i][j] << " " ;
            }
            os << '\n';
        }
        return os;
        }
    };
}