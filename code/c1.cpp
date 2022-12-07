// U1 S1

/**
VARIABLE: espacio de memoria que aloja un tipo de dato
    let var1;
    int var1;
    var1 = None
    var1 = ""
    var1 = 1
MEMORIA: coleccion de bytes(8 bits), registros
TD: 
    mecanismo que define la forma en que debe tratarse la data
    abstrae de la forma de usar la data
    RESTRICCIONES:
        type casting
    OPERACIONES:
        sobrecarga

enum
    Una enumeración es un tipo definido por el usuario que consta de un conjunto de constantes enteras con nombre conocidas como enumeradores.

namespace
    A namespace is a collection of related names or identifiers (functions, class, variables) which helps to separate these identifiers from similar identifiers in other namespaces or the global namespace
    The identifiers of the C++ standard library are defined in a namespace called std .
    
    Nivel adicional de abstraccion
    Todo lo que este dentro, estan asociadas a ese namespace

    :: scope operator 
        -> operador de alcance
        -> le dice al compilador en que clase/namespace buscar un identificador
PUNTERO:
    tipo de dato que aloja una direccion de memoria (pesa 8 bytes)

DIRECCIONDEMEMORIA:
    lugar donde esta guardado, se representa en hexadecimal
    ejm: 0x7ffed8f4b8b4
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// using namespace other_namespace;

template<class T>
void PRINT_VEC(vector<T>& v) { cout << "[ "; for (auto el : v) cout << el << " "; cout << "]"; }

struct S{

};

class C{
protected:
private:
public:
};

void td_ejemplo()
{
    int n = 64;
    char c = 64;

    cout<<"64 -> int:  "<<n<<'\n';
    cout<<"64 -> char: "<<c<<'\n';

    cout<<"char -> 64: "<<int(c)<<'\n';

    // string s = " ";
    // cout<<n+s<<'\n';
}

void enum_ejemplo()
{
    enum num {zero, one, two, three};       // indexa en 0
    // cout<<zero<<endl;
    // cout<<one<<endl;
    // cout<<two<<endl;
    // cout<<three<<endl;

    vector<int> vec{3, 0, 2, 1};
    for (const int& v: vec)
    {
        switch (v)
        {
            case zero:
                cout<<"this is 0\n";
                break;
            case one:
                cout<<"this is 1\n";
                break;
            case two:
                cout<<"this is 2\n";
                break;
            case three:
                cout<<"this is 3\n";
                break;
            default:
                break;
        }
    }

    enum direction { left = 'l', right = 'r' };
    cout<<left<<endl;
    cout<<right<<endl;
}


namespace my_algorithms {
    template<typename it>
    void sort(it beg, it end)
    {
        cout<<"ordenando contenedor ... \n";
        return;
    }
}

namespace graph_alg {
    void bfs()
    {
        cout<<"BFS\n";
    }

    void dfs()
    {
        cout<<"DFS\n";
    }
}

namespace sort_alg {
    void intro_sort()
    {
        cout<<"INTROSPECTIVE SORT\n";
    }

    void quick_sort()
    {
        cout<<"QUICK SORT\n";
    }
}

int main()
{
    vector<long long int> numbers {17, 5, -7, 21, 12, 3};
    my_algorithms::sort(numbers.begin(), numbers.end());
    sort(numbers.begin(), numbers.end());

    PRINT_VEC(numbers);
    cout<<endl;

    graph_alg::bfs();
    sort_alg::intro_sort();


    int n = 5;
    int* ptr_n = &n;

    cout<<&n<<endl;
    cout<<ptr_n<<endl;      // direccion de memoria
    return 0;
}
/*
https://www.w3schools.com/charsets/ref_html_ascii.asp 
*/



/*
* COMMING SOON
    constructor move, asignacion, convertibles
        ejm pendiente
    friend
        ejm: entre una clase y un método especifico de una clase
    argc, argv
        ejm
    std::nothrow
        ejm pendiente
*/