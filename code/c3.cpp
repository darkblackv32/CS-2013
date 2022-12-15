#include "c3.h"
using namespace utec;

typedef long long ll;
#define pb push_back        // MACRO
#define all(v) v.begin(), v.end()
#define endll '\n'
#define f(i,a,b) for(ll i = a; i<b; i++) 

void ejm0(), ejm1(), ejm2(), references(), grafos();


const ll max_N = 100 + 5;
ll graph[max_N][max_N];

int main()
{
    // references();
    // ejm0();
    // ejm1();
    // ejm2();
    // grafos();
}

void ejm0()
{
    point_t p0;

    cout<<"inner scope\n";
    {
        point_t _p0;
    }
    cout<<"-----------\n";
}

void ejm1()
{
    point_t p0;
    cout<<p0<<endl;
    point_t p1(4, 5);

    // vector<pair<ll, int>> vpares;
    pair<int, int> par(10, 20);
    point_t p2(par);

    // cout<<p1<<" "<<p2<<endl;

    point_t p3(p2), p4 = p2;        // two ways to call copy constructor
    point_t p5;
    cout<<"p2 -> "<<p2<<endl;
    cout<<"p3 -> "<<p3<<endl;

    p4 = p2;    // copia por reasignacion != construction
    p5 = p3;    // * COPY ASSIGNMENT (lvalue)
    cout<<"p4 ->"<<p4<<endl;
    cout<<"p5 ->"<<p5<<endl;
}

void ejm2()
{
    vector<point_t> points;
    points.pb(point_t(1, 2));
    cout<<points[0]<<endl;

    cout<<points.size()<<" "<<points.capacity()<<endl;
    points.pb(point_t(3, 4));
    cout<<points.size()<<" "<<points.capacity()<<endl;
    points.pb(point_t(5, 6));
    cout<<points.size()<<" "<<points.capacity()<<endl;
    points.pb(point_t(7, 8));
    cout<<points.size()<<" "<<points.capacity()<<endl;
    points.pb(point_t(9, 10));
    cout<<points.size()<<" "<<points.capacity()<<endl;

    cout<<points[5]<<endl;
    points[5] = point_t(11, 12);        // * MOVE ASSIGNMENT (rvalue)
    cout<<points[5]<<endl;

    point_t p_example;
    p_example = point_t(13, 14);        // * MOVE ASSIGNMENT (rvalue)
    cout<<p_example<<endl;
}

void references()
{
    point_t p0;         // * lvalue: tiene asignado una porcion de memoria
    // REFERENCIA A UN LVALUE
    point_t& lref = p0;
    
    // point_t& lref_error = point_t(4, 5);

    // REFERENCIA A UN RVALUE
    point_t&& rref = point_t(4, 5);

    int j = 5;
    // point_t(4, 5) + point_t(5, 7) = point_t(9, 8);
    // point_t(4, 5) = point_t(7, 9);
}

void grafos()
{
    // REPRESENTACION DE GRAFOS COMPUTACIONAL CON STL

    // LISTA DE PARES -> MST(KRUSKAL)
    vector<pair<ll, pair<int, int>>> tree;
        // tree = { {weight, {a, b}} } 
    // MATRIZ DE ADYACENCIA -> O(N^2) | denso o esparso
    auto matriz = vector<vector<ll>>(max_N, vector<ll>(max_N));
    
    // LISTA DE ADYACENCIA -> DFS, BFS, DIJKSTRA
    vector<vector<ll>> adj(max_N, vector<ll>());
    /*
    1 2
    2 3
    1 3

    graph[1] = {2, 3}
    graph[2] = {1, 3}
    graph[3] = {1}
    */
}

/**
 * ESTADISTICA
 *  https://www.fcfm.buap.mx/jzacarias/cursos/estad2/libros/book5e2.pdf
 * PROGRA3
 * BD1
 *  Modelo logico, fisico
 *  Algebra relacional, Funciones de agregacion
 *  Optimizacion de consultas
 *  SQL
 * DBP
 *  FCC Backend (ExpressJS, NodeJS, MongoDB(NoSQL))
 *  Python(Flask)
 *  BD Relacional (SQL)
 * OPTICA Y ONDAS
*/