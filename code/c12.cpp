

/*

SOFTWARE
    WEB (Create Read Update Delete)
        Front
            ReactJS
            Angular
            VueJS
        Back
            Python Django (MVC)
            NodeJS
                Express
                NestJS
                NextJS
        BD
            SQL
                Postgres
            NoSQL
                MongoDB
        
    MERN
        Mongo Express React NodeJS
    MEVN

    Fundamentos: PHP
    ...
    Orquestadores de tares
        Apache Airflow
    Streaming
        Apache Kafka
*/

#include <bits/stdc++.h>
using namespace std;

#define all(cont) begin(cont), end(cont)

template<typename T = int>
struct Point {
private:
    int K;
public:
    typedef T tipo_punto;
    vector<T> p;
    Point() = default;
    Point(int k): K{k} { p = vector<T>(k); }
};

template<typename T>
istream& operator>>(istream& is, Point<T>& point)
{
    for (T& value : point.p)
        is >> value;
    return is;
}

template<typename T>
ostream& operator<<(ostream& os, Point<T>& point)
{
    os << "{ ";
    for (T& value : point.p)
        cout << value << " ";
    os << "}";
    return os;
}

/*
Arboles
    grafo aciclico y conexo
    arbol binario
        a lo mucho 2 hijos

        arbol binario de busqueda


*/

void ejemplo1()
{
    /*
    Given N k-dimensional points in the space
    The task is sort the points by the x-coordinate, y-coordinate and so on...
    (x, y, z, ....)
        (1, 2, 4, ...) (1, 2, 5, ...) 
    */
    int N, K;
    cin >> N >> K;
    using tipo = int;
    vector<Point<tipo>> points(N, Point(K));
    while (--N >= 0)
    {
        cin >> points[N];
        // cout << points[N] << endl;
    }
    // using tipo = decltype(points[0])::tipo_punto;
    sort(all(points), [K](const Point<tipo>& first, const Point<tipo>& second)
    {
        for (int i = 0; i < K; i++)
        {
            if (first.p[i] < second.p[i])
                return true;
            else if (first.p[i] > second.p[i])
                return false;
        }
        // points are same
        return true;
    });

    for (auto punto : points)
        cout << punto << " ";
    cout << endl;
}

int parent(int i){ return i/2; }
int left(int i){ return 2*i; }
int right(int i){ return 2*i + 1; }

template<typename T = int/*, typename Comparer = greater<T>*/>
struct heap
{
private:
    vector<T> arr = {T()};
    // Comparer comp;

    void heapify_up(int idx_child)
    {
        int idx_parent = parent(idx_child);
        while (idx_child > 1 && 
                arr[idx_parent] > arr[idx_child]        // cambiarlo a max-heap con <
                // comp(arr[idx_parent], arr[idx_child])
        )      // >
        {
            swap(arr[idx_parent], arr[idx_child]);
            idx_child = idx_parent;
            idx_parent = parent(idx_child);
        }
    }
public:
    heap() = default;
    // heap(Comparer new_comp): comp{new_comp}{};       // * IDEA

    void insert(T new_el)
    {
        arr.push_back(new_el);
        int last_idx = arr.size()-1;
        heapify_up(last_idx);
    }

    void print()
    {
        cout <<"[ ";
        for (int i = 1; i < arr.size(); i++)
            cout << arr[i] << " ";
        cout <<"]\n";
    }
};


int main()
{
#ifndef TEST
    freopen("input.txt", "r", stdin);
#endif
    heap my_heap;
    int new_value;
    while (cin >> new_value)
    {
        my_heap.insert(new_value);
        my_heap.print();
    }
    return 0;
}