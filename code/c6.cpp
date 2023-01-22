#include <iostream>
using namespace std;

// auto sum()
// { 
//     printf("  %s\n", __PRETTY_FUNCTION__);
//     return 0; 
// }

// template<typename T>
// T sum(T last)
// { 
//     cout << last;
//     printf("  %s\n", __PRETTY_FUNCTION__);
//     return last; 
// }

// template<typename T, typename V>
// auto sum(T penultimo, V ultimo)
// { 
//     cout << penultimo << " " << ultimo;
//     printf("  %s\n", __PRETTY_FUNCTION__);
//     return penultimo + ultimo; 
// }

template<typename... pack/*, typename first*/>
auto sum(/*first F,*/pack... P)
{
    // cout << F;
    printf("  %s\n", __PRETTY_FUNCTION__);

    // * USE RECURSION
    // auto res = F + sum(P...);            // P... significa desempacar los parametros
    // return res;
    
    // cout<<" "<<sizeof...(P)<<"\n";       // tama;o del pack de parametros

    // * FOLD EXPRESSION
    // 1LL, 2, 2.5, size_t(3)

    return (P + ...);
    // (1LL + (2 + (2.5 + size_t(3))))

    return (... + P);
    // (((1LL + 2) + 2.5) + size_t(3))
}

bool allVar() {                                              // (1)
    return true;
}

template<typename T, typename ...Ts>                         // (2)
bool allVar(T t, Ts ... ts) {                                // (3)
    return t && allVar(ts...);                               // (4)
}

template<typename... Args>                                   // (5)
bool all(Args... args) { return (... && args); }

int main()
{
    cout << sum(1LL, 2, 2.5, size_t(3)) << endl;
        // 1 + sum(2, 2.5, size_t(3))
        //      2 + sum(2.5, size_t(3))
        //          2.5 + sum(size_t(3))
        //              3 + sum()
        //                  0

    auto a1 = 1 + 2.5;
    auto a2 = 1LL + 2.5;

    cout << a1 << " " << a2 << endl;


    cout << boolalpha << '\n';
    cout << "allVar(): " << allVar() << '\n';
    cout << "all(): " << all() << '\n';

    cout << "allVar(true): " << allVar(true) << '\n';
    cout << "all(true): " << all(true) << '\n';

    cout << "allVar(true, true, true, false): " 
              << allVar(true, true, true, false) << '\n';
    cout << "all(true, true, true, false): " 
              << all(true, true, true, false) << '\n';
                // (((true && true) && true) && false)
    cout << '\n';
}
