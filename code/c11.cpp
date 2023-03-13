#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <random>
#include <deque>
using namespace std;

/*
STL
    libreria compuesta por full templates
    
    containers, iterators, algorithms

    CONTAINERS
        colecciones de elementos
            with underlying 'data structures'
                memoria contigua o no
    ITERATORS
        clase/struct/objecto que simula el comportamiento de un puntero clasico
            dereference
            reassign
            save a address memory
        interfaz de comunicacion entre containers y algorithmos genericos
    
    ALGORITHMS
        CS: secuencia de pasos para resolver tareas, pasos finitos, secuencial
        funciones built-in
        STL: implementaciondes de algoritmos(CS) conocidos, usados comunmente, son genericos (templates)
*/


void foo()
{
    cout << __PRETTY_FUNCTION__ << endl;
}

void print_str(const string& value, string sep = "\n") 
{
    cout << __PRETTY_FUNCTION__ << endl;
    cout << value << sep;
}
// auto suma(int, int)
// auto suma(double, int)
// auto suma(int, double)
// auto suma(int, int, double, int)

void capa_superior(
    void (*cualquier_funcion)() /* address | return_type (*var_name) (type_arg1, type_arg2 .. type_argn) */
)
{
    cout << __PRETTY_FUNCTION__ << endl;
    cout << "\t";
    cualquier_funcion();
}

void capa_superior(
    void (*cualquier_funcion)(const string&, string)
)
{
    cout << __PRETTY_FUNCTION__ << endl;
    cout << "\t";
    cualquier_funcion("","");
}

void pointer_to_function()
{
    // callables -> llamables -> is any object that can be called like a function.
    // all save in any memory space
    
    foo();
    printf("%p\n", foo);        // cout << &foo << endl;
    
    // if the functions have address memory it can be referenced by a pointer
    // * 1. pointer to function
    // SYNTAXIS: return_type (*var_name)(type_arg1, ..., type_argn) = &func
    
        // void (*pFoo)() = &foo;
    void (*pFoo)() = nullptr;       // initialization
    pFoo = &foo;                    // reassign
    auto pFoo2 = pFoo;

    // int (*pMain)() = &main;
    void (*pPrintStr)(const string&, string) = &print_str;
    
    cout << typeid(pFoo).name() << endl;
    // cout << typeid(pMain).name() << endl;
    cout << typeid(pPrintStr).name() << endl;
    
    pPrintStr("12345678", "\nsep\n");
    // ? if a "pointer to function" save and addrees memory, it can be passed as a function argument
    printf("%p %p %p %p\n", &pFoo, pFoo, *pFoo, foo);        // address, address of a function
    // printf("%p %p %p %p\n", &pMain, pMain, *pMain, main);
    printf("%p %p %p %p\n", &pPrintStr, pPrintStr, *pPrintStr, print_str);

    // int a = 5;
    // int* b = &a;
    // cout << b << " " << *b << " " << &b << endl;   // value of pointer, *(value_of_pointer), address of variable
    capa_superior(pFoo);
    capa_superior(print_str);
}


void swap_pair(pair<int, int>& p)
{
    int temp = p.first;
    p.first = p.second;
    p.second = temp;
}

template<typename T>
void add_substract(pair<T, T>& par)
{
    par.first -= 1;
    par.second += 1;
}

template<typename X /*= pair<int, int>*/>
void manipulate(vector<X> &vec, void (*criteria)(X&) /*semitemplatizado*/)
{
    for (X& elemento : vec)    
        criteria(elemento);
}

class Wrapper {
public:
    void operator()(pair<int, int>& p)
    {
        cout << __PRETTY_FUNCTION__ << endl;
        int temp = p.first;
        p.first = p.second;
        p.second = temp;
    }

    static void print()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    template<typename X>
    static void swap(pair<X, X>& p)
    {
        // https://stackoverflow.com/questions/31394507/how-can-i-emulate-destructuring-in-c
        cout << __PRETTY_FUNCTION__ << endl;
        // X f, s, temp;
        // tie(f, s) = p;      // std::tuple ....
        X temp = p.first;
        p.first = p.second;
        p.second = temp;
    }
};

class obj_func {
public:
    void operator() ()
    {

    }
};

void functor_std_function()
{
    
    // passed pointer to functions as arguments
    vector<pair<int, int>> vpp = { {1, 2}, {3, 4}, {5, 6} };
    for (auto &i : vpp) cout << " {" << i.first << " " << i.second << "} "; cout << endl;

    // TODO: create a manipulate() function that alterates each pair of a vector<pair<>> by certain criteria
    manipulate(vpp, swap_pair);
    for (auto &i : vpp) cout << " {" << i.first << " " << i.second << "} "; cout << endl;

    void (*p_add_sub)(pair<int, int>&) = &add_substract<int>;
    manipulate(vpp, p_add_sub);
    for (auto &i : vpp) cout << " {" << i.first << " " << i.second << "} "; cout << endl;
    
    // referenced by pointers to class methods
    void (*p_class_swap)(pair<int, int>&) = &Wrapper::swap<int>;        
    void (*p_class_print)() = Wrapper::print;

    manipulate(vpp, p_class_swap);
    for (auto &i : vpp) cout << " {" << i.first << " " << i.second << "} "; cout << endl;

    // static allows to call without object instantiation
    Wrapper::print();       // static
    Wrapper ww;
    ww.print();
    p_class_print();
    
    
    (Wrapper::print)();
    (ww.print)();
    
    // ? problemas de los punteros -> dangling pointers, circular references <- smart_pointers...
    // * std::function -> acepta functiones, metodos de funciones y todo aquello que sea callable (lambda)
    function<void(pair<int, int>&)> fSwap = &Wrapper::swap<int>;
    function<void()> fPrint = &Wrapper::print;

        // lamdba: inline function, nonnamed function
    obj_func ob1;
    ob1();

        // generate random numbers
    int mn = -1;
    int mx = 1;
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> dist(mn, mx);

}

int GLOBAL = 5;

template<typename T, template<class, class> class Container, typename Criteria>
void manipulate(
    Container<T, std::allocator<T>> contenedor,
    Criteria crit
)
{
    for (T& elemento: contenedor)
        crit(elemento);
}

int main()
{
    deque<double> d {1.23, 2.34, 3.45, 4.56, 5.67};
    int multiplicador = 2;
    manipulate(d, [multiplicador](double& elemento){
        elemento *= multiplicador;
    });

    /*
    LAMBDA 
        inline function which can be
            passed as an argument to another (pointer to function)
            used for short snippets that are not reused (used inside scope)
        an unnamed function object capable capturing variables in scope
    */
    int i = 2, j = 5;

    auto print_lambda = [&i, j/*capture*/](/*argument list*/int& a /*, void(*func)()*/) {
        // body
        a += i;
        i+=1;
        // cout << GLOBAL << endl;
    };
    int aa = 2;
    cout << aa << endl;
    print_lambda(aa);
    cout << aa << endl;
    cout << i << endl;
    /*
    capture
        'capturar' variables fuera del lambda
        capture arguments
            [&]         external variables by reference
            [=]         external variables by value
            var1, &var2, &var, ...
    */

    auto print_lambda_template = []<typename T>(T value, string sep) -> void {
        cout << value << sep;
    };
    return 0;
}


/**
1. pointer to function
    Pointers are symbolic representations of memory addresses
    Enable programs to call-by-reference, create and manipulate DS

    Address of function 
        all code resides in memory (templates relevance)
        is stored in a pointer
        every function has an address like all other variables in the program
    Function pointer
        used to point functions
        syntax:
            return_type (*FuncPtr) (parameter type, ....);  
            return_type (*FuncPtr) (parameter type, ....) = &function_name;
        as well as pointers to other types function pointers...
            can be passed as arguments to other functions
            can be referencing and dereferencing

https://stackoverflow.com/questions/10442404/invoke-a-c-class-method-without-a-class-instance
https://www.geeksforgeeks.org/function-pointer-in-cpp/
https://www.learncpp.com/cpp-tutorial/function-pointers/
https://www.cprogramming.com/tutorial/function-pointers.html

2. std::function
3. functor
4. lambda
inline function which can be 
    passed as an argument to another function
    used for short snippets of code that are not reused

an unnamed function object capable of capturing variables in scope.

https://iq.opengenus.org/std-function/
https://www.tutorialspoint.com/cpp_standard_library/functional.htm
*/