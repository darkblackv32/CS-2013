/*
RA -> []
FW -> next()
BI -> next() prev()
*/

#include <bits/stdc++.h>
using namespace std;

void vistazo_librerias()
{
    vector<int> vec {1, 2, 3, 4, 5};
    vector<int>::iterator bv = begin(vec);
    // __gnu_cxx::__normal_iterator<pointer, vector> beg = begin(vec);


    list<int> ls {1, 2, 3, 4, 5};
    list<int>::iterator bl = begin(ls);
    // _List_iterator<_Tp> bl = begin(ls);
}

int main()
{
    std::array<double, 3> arr_0 = {1.4, 1.5, 1.7};
    std::array arr_1 = {10, 20, 30, 40, 50};
        // xa0 xa4 xa8      int
        // xa0 xa8 xb0      double
    int* arr = new int[5];
        // when use? -> fixed number of elements, known at compile time

        // std::reverse_copy
    std::reverse_copy(
        begin(arr_1),           // algoritmo (non member)
        arr_1.end(),            // metodo (member)
        std::ostream_iterator<int>(std::cout, " ")
    );  cout<<endl;
    // cout (console output) | cerr (console error) | cin (console input)

    int* ptr_ini = arr_1.data();
    decltype(arr_1)::iterator ptr_end = arr_1.data() + arr_1.size();    // pointer to the next of last element
    cout<< ptr_ini << " " << ptr_end << endl;
    while (ptr_ini != ptr_end)
        cout<< *ptr_ini++ <<" ";
    
    std::vector<double> vd;     // []
    // *ACCESO ALEATORIO: xa0 + 8*n = la dir.mem. elemento en la posicion n
    // | | | | | | 2^n | .... | 2^(n+1) | ... |
    // *USO DE MEMORIA: 129 elementos requieren 256 celdas de memoria contigua
    // !ELIMINACION: size-- /2          127 elementos 256 celdas
    // !INSERCION: size++ condicionado a redimensionamiento
        // 180 256    127 128    64 64    2 256
        // n elementos log2(n) veces
        // []
        // [1]      |       log2(1) = 0
        // [1, 2]   ||      log2(2) = 1
        // [1...4]  |||     log2(4) = 2
        // [1...8]  ||||    log2(8) = 3
        
        // [1 2 3 4 5]
        // [1 2 x 4 5] size--
        // [1 2 4 5 x]

    // | xa0 | -> | xf1 | -> | xb6 |
    // | xa0 | ---> | xb6 |
        // when use? -> dynamic number of elements, unknown at compile time 
    
    std::deque<int> dq;     // dynamic semi-continuous memory allocation
        // double ended queue
    /*
    map []
    buckets [] [] [] []

    [] [] [] 
    bucket
        cap = 5
        size

    10
    10/5 = bucket
    10%5 = posicion en el bucket
    
    
    [b1, b2, b3 b4]
    [8 15 23] [45 52 32] [40 80 20] [50 60 70]         cap=3

    0
    0/3 = 0
    0%3 = 0
    
    1/3 = 0  bucket
    1%3 = 1  pos en bucket

    11/3 = 3
    11%3 = 2

    vector
    [64] [dataframe]
            [128]

    deque
    [map: n/size_bucket]
        []
        []
        []
    */
    // https://www.codeproject.com/Articles/5425/An-In-Depth-Study-of-the-STL-Deque-Container
        // when use? -> dynamic number of elements, unknown at compile time 
    
    std::list<int> lst;             // doubly linked list
    // <- | xa0 | <-> | xf1 | <-> | xb6 | ->        [2]

    // circular doubly linked list
        // | xb6 | <- | xa0 | <-> | xf1 | <-> | y78 | <-> | xb6 | ->| xa0 |
    // doubly skip linked list
        // http://www.cs.emory.edu/~cheung/Courses/253/Syllabus/Map/FIGS/skip-list02a.gif
    std::forward_list<int> flst;    // simply linked list
    // | xa0 | -> | xf1 | -> | xb6 |        [2]
    return 0;
}


// template<typename T>
// class BST{
//     Node<T>* node;
// };

// template<typename T>
// class SparseMatrix{};