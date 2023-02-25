/*
CRUD -> Create Read Update Delete

std::array
    tamano fijo
    [] -> O(1)
        reasignacion  arr[n] = val
        acceso        arr[n]

        int | xa0 + 1 = xa4
    array<T, size_t>
std::vector
    permite redimension (2^N)
    insercion al final O(1) push_back
    eliminar elementos != del ultimo O(n)
    busqueda O(n)
    update
        vec[pos] = new_val      O(1)
    memoria contigua [a1, a2, a3, a4 ]

std::deque
    front y back | push y pop
        insercion O(1)    

    delete O(n)
    update O(1)
    memoria discontigua [a1 a2] [a3 a4] [a5 a6]

std::set
    memoria por nodos dado que es un arbol (grafo aciclico y conexo)
    ordenado
    elementos unicos
std::map
    diccionario
*/

/*
* ITERADORES
    como un puntero
        begin() -> apunta a la primera casilla de un contenedor
        end() -> apunta a la siguiente casilla del ultima casilla del contenedor

    object that generalize the behaviour and the concept of a pointer
    encapsulates the internal structure of how the iteration works
    is the interface to communicate containers with algorithms
*/

#include <bits/stdc++.h>
using namespace std;

// function to return the iterator type
template<typename T>
string get_iterator_type(T it)
{
    // if the iterator category of (it) matches input
    if (typeid(typename iterator_traits<T>::iterator_category)
        == typeid(input_iterator_tag))
        return "Input";
  
    // if the iterator category of (it) matches output
    else if (typeid(typename iterator_traits<T>::iterator_category)
             == typeid(output_iterator_tag))
        return "Output";
  
    // if the iterator category of (it) matches forward
    else if (typeid(typename iterator_traits<T>::iterator_category)
             == typeid(forward_iterator_tag))
        return "Forward";
  
    // if the iterator category of (it) matches bidirectional
    else if (typeid(typename iterator_traits<T>::iterator_category)
             == typeid(bidirectional_iterator_tag))
        return "Bidirectional";
  
    // if the iterator category of (it) matches random_access
    else if (typeid(typename iterator_traits<T>::iterator_category)
             == typeid(random_access_iterator_tag))
        return "Random_Access";
  
    // if the iterator category of (it)
    // does not match any of the above
    return "Missing";
}

template<typename iterator_>
string get_it_name()
{
    return typeid(
        typename iterator_traits<iterator_>::iterator_category
    ).name();
}

int main()
{
    std::vector<int> vec {10, 20, 30, 40, 50};      // memoria contigua
    for (const int& v : vec)
        cout<<v<<" ";
    // sort(begin(vec), end(vec));
    std::set<int> st {1, 2, 3, 4, 5};               // memoria por nodos (left root right -> INORDER)
    for (const int& s : st)
        cout<<s<<" ";
    // sort(begin(st), end(st));
    
    vector<int>::const_iterator cb = vec.cbegin();     // avanzar pero no editar valor  // member
    cb++;
    const vector<int>::const_iterator ccb = cbegin(vec);        // ni avanza ni edita    // non-member
    // ccb++;       // ! error


    initializer_list<int> ls = {5, 4, 3, 2, 1};

    initializer_list<int>::value_type entero = 1;       // identificar el tipo base del contenedor a partir del contenedor mismo
    decltype(ls)::size_type szt = 2;
    // template<typename container>

    auto beg = vec.begin();
    auto en = end(vec);
    iterator_traits<decltype(beg)>::value_type enter = 4;       // identificar el tipo base del contenedor a partir del iterador del mismo contenedor
    // template<typename iterator>
    /*
    * ITERATOR TRAITS
        allows implement algorithms only in terms of iterators
        allows to implement algorithms that work with any type of container

        https://cplusplus.com/reference/iterator/iterator_traits/
        
        value_type
        iterator_category
            https://www.boost.org/sgi/stl/iterator_category.html
        difference_type 
            https://stackoverflow.com/questions/46695349/how-to-handle-iteratordifference-type-when-you-have-no-way-of-measuring-the-di
            std::ptrdiff_t
                std::ptrdiff_t is the signed integer type of the result of subtracting two pointers. 
        pointer
        reference
    */
    // * get iterator type (trait) as string
    cout<<endl;
    cout << typeid(
        typename iterator_traits<decltype(beg)>::iterator_category
    ).name() <<endl;
    cout << get_it_name<decltype(beg)>() << endl;
    cout << get_iterator_type(beg) << endl;

    cout<<get_it_name<deque<double>::iterator>() << endl;       // random
    cout<<get_it_name<list<double>::iterator>() << endl;        // bidir
    cout<<get_it_name<forward_list<double>::iterator>() << endl;    // forward
    cout<<get_it_name<set<size_t>::iterator>() << endl;    // bidir
    cout<<get_it_name<map<int, string>::iterator>() << endl;        // bidir

    // https://cplusplus.com/reference/iterator/

    // ++r vs. r++
    // str += "a"; O(n)  || str.push_back("a")  O(1)
    cout << "Ingrese un número separado por espacios y escriba \\0 para finalizar:" << endl;
    cout << "La suma de los valores ingresados es:" 
        << accumulate(
            istream_iterator<double>(cin),
            istream_iterator<double>(), 0.0
        ) << endl;      // \0 end of a string
    char c = '\0';      // ? research C, CtrlC CtrlZ \0 -1 false
    // \n \b \0 \t
    string str = "adssfjsadlfjsadklfsdjafklsda";
}