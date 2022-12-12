#include "c2.h"
using namespace std;
// using namespace soldi;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vint;
typedef deque<int> dint;

ll NUM_GLOBAL;

template<class T>
void PRINT_VEC(vector<T> &v) { cout << "[ "; for (auto el : v) cout << el << " "; cout << "]"; }

void namespace_amistad_clases(), referencias(), referencias_2(), mostrar_ll(const ll&);
ll& suma(ll a, ll b);

int main() 
{
    // namespace_amistad_clases();
    // referencias();
    referencias_2();
}

void mostrar_ll(const ll& num)
{
    // num = -1;
    cout<<num<<endl;
}

ll& suma(ll a, ll b)
{
    NUM_GLOBAL = a + b;
    return NUM_GLOBAL;
}

void referencias_2()
{
    ll& NUM_ALTERNATIVO_GLOBAL = suma(5, 4);
    cout<<NUM_GLOBAL<<" "<<NUM_ALTERNATIVO_GLOBAL<<endl;
    NUM_ALTERNATIVO_GLOBAL = 5;
    cout<<NUM_GLOBAL<<" "<<NUM_ALTERNATIVO_GLOBAL<<endl;
}

void referencias()
{
    /**
    REFERENCIAS: 
        nombre alternativo a una variable
    VARIABLE:
        espacio de memoria ...
    */
    ll mil = 1e3;

    // a variable can be declared as a reference by putting '&' in the declaration
    ll& ref_mil = mil;      // definiendo una referencia a otra variable

    cout<<&ref_mil<<" "<<&mil<<endl;
    ref_mil = 1e2;
    cout<<ref_mil<<" "<<mil<<endl;
    mil = 1e3;
    cout<<ref_mil<<" "<<mil<<endl;

    ll mil_2 = mil;
    mostrar_ll(mil);
    cout<<ref_mil<<" "<<mil<<endl;
    /**
    LVALUE:
        "todo lo que puede estar a la izquierda"
        siempre esta a un espacio de memoria

        ... is an expression that yields an object reference
        ... always has a defined region of storage, so you can take its address
        
        ... objeto que persiste mas alla de una expression
        
        ... refers to memory location which identifies an object
        ... l-value may appear as either left hand or right hand side of an assignment operator (=)
        ... the name of identifier denotes a storage location, while the value of the variable is the value stored at the location

        USES:
            ... lvalue references can be used to alias an existing object
            ... they can also be used to implement pass-by-reference semantics
        EJM:
            variable name
            array subscript reference
            dereference pointer
            function call that returns a reference
            
    RVALUE:
        "solo lo que puede estar a la derecha"
        no necesariamente sucede eso

        ... is an expression that is not an LVALUE.
        ... valor temporal que no persiste mas alla de la expresion en la que se usa.
        
        ... simply means, an object that has not identifiable location in memory (i.e. having an address)
        
        ... rvalue references extend the lifespan of the temporary object to which they are assigned
        ... non-const rvalue references allow you to modify the rvalue
        
        USES:
            ... move constructor and move assignment

        EJM:
            constant/literals
            results of most operators (expr like a+b will return some constant)
            function call that return nonreferences
            anything that is capable of returning a constant expression or value
    */
    ll n = 1LL;

    ll y = 6+7;
    // 6+7 = 5;
    cout<<5+4<<endl;
    n = 5LL;        // lvalue = rvalue
    ll m = n;

    // 5LL = n;        // error

    int i = 1, j=5;
    // TERNARY OPERATOR: <condition> ? <if-true> : <else>
    ((i < 3) ? i : j) = 7;

    cout<<i<<" "<<j<<endl;

    int *ptr_i = nullptr;
    ptr_i = &i;
    *ptr_i = 2;
    
    cout<<i<<" "<<j<<endl;

    // ! REVISAR CODE
    int var2 = 20;
    const int& ref_var2 = var2;     // referencia constante a un lvalue
    cout<<sizeof(ref_var2)<<" -> "<<&ref_var2<<" "<<&var2<<endl;
    // ref_var2 = 10

    const int& ref_20 = 20;         // referencia constante a un rvalue
    cout<<&ref_20<<" "<<endl;

    int var1 = 10;
    int& lref = var1;
    int&& rref = 20;

    cout<<lref<<" | "<<rref<<endl;
    lref = rref;        // lref = 20
    rref = var1;        // rref = 10, doesn't return error
    cout<<lref<<" | "<<rref<<endl;
    rref = 40;
    cout<<lref<<" | "<<rref<<endl;

    /**
        https://www.tutorialspoint.com/cplusplus/cpp_constants_literals.htm
        https://www.oreilly.com/library/view/c-in-a/059600298X/ch03s01.html
        https://es.stackoverflow.com/questions/914/diferencias-entre-rvalue-y-lvalue
        https://learn.microsoft.com/en-us/cpp/cpp/lvalues-and-rvalues-visual-cpp?redirectedfrom=MSDN&view=msvc-170
        https://www.geeksforgeeks.org/lvalue-and-rvalue-in-c-language/
        https://www.geeksforgeeks.org/lvalues-references-and-rvalues-references-in-c-with-examples/
    */

    // PENDIENTE: std::move
}

// ll suma(ll a, ll b)
// {
//     return a + b;
// }

void namespace_amistad_clases()
{
    vll num {1LL, 0LL, ll(1e9), ll(1e5 + 10)};
    cout<<"interesting numbers -> "<<1e5+((1e5-1)*1e5)/2<<endl;        // 5.00005e+09 = 5000050000

    // STL
    vint v1(5, -2);
    cout<<"vector<int> alias vint v1 -> ";
    PRINT_VEC(v1);
    cout<<endl;

    dint d1;
    d1.push_front(1);
    d1.push_back(2);

    d1[0] = 5;
    cout<<"deque<int> alias dint d1 -> [ ";
    for (int i=0; i<d1.size(); ++i)
        cout<<d1[i]<<" ";
    cout<<"]\n";

    // MY NAMESPACE
    soldi::vint v2;
    v2 = soldi::vint(5, -2);
    cout<<"v2 -> ";
    cout<<v2<<endl;

    soldi::dint d2(4, 1);
    d2[2] = 2;
    // 1 = 2;

    cout<<"d2 -> [ ";
    for (int i=0; i<d2.sz(); ++i)
        cout<<d2[i]<<" ";
    cout<<"]\n";

    d2.copy_from_vint(v2);

    cout<<"v2 copy to d2 -> [ ";
    for (int i=0; i<d2.sz(); ++i)
        cout<<d2[i]<<" ";
    cout<<"]\n";
}


/**
 CONSTRUCTORES:
    default
    parametrizado
    
    copia
    asignacion

    move
    asignacion move
*/