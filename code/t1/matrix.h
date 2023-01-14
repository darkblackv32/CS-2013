#pragma once
#include <iostream>
#include "number.h"
using namespace std;

namespace utec{

    
    class matrix_t
    {
    private:
        int rows;
        int cols;
        number_t*** mat;
        friend ostream &operator<<(ostream &os,  matrix_t& m);


    public:

        matrix_t() = default;

        matrix_t(const int _rows, const int _cols) : rows(_rows), cols(_cols){
            mat = new number_t**[_rows];
            for(int i = 0; i < _rows; i++){
                mat[i] = new number_t*[_cols];
            }
        }
        
        int row_size(){return rows;}
        int col_size(){return cols;}


        number_t*& operator()(int i, int j){
            
            return mat[i][j]; // *&mat[i][j];
            
        }
        
        ~matrix_t(){
            for(int i=0; i< rows; i++){
                    delete [] mat[i];
                delete [] mat;
                mat = nullptr;
                break;}
            }

        };
        
        ostream &operator<<(ostream &os, number_t &n){
            n.out();
            return os;
        }

        ostream &operator<<(ostream &os, matrix_t &m) {
            for (int i=0; i < m.rows; ++i){
                for (int j=0; j < m.cols; ++j) {
                        os << *m.mat[i][j] << " " ;
                    }
                    os << '\n';
                }
                return os;  
        }

        

}