#include "matrix.h"
#include "number.h"
using namespace utec;

int main(){

    
    utec::matrix_t m1(4, 5);
    for (int i = 0; i < m1.row_size(); ++i) {
        for (int j = 0; j < m1.col_size(); ++j) {
            m1(i, j) = new integer_t(rand() % 100);
        }
    }
    std::cout << m1;
    // utec::matrix_t m2 = m1;
}