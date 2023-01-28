#include <iostream>
#include <array>
#include <tuple>
using namespace std;
// using namespace std;
// template<typename T, size_t N>
// int init_array(T (&a)[N]){
//     for(int i = 0; i < N; ++i){
//         a[i] = i;
//     }
//     return 0;
// }

// template<typename T, size_t N>
// int init_array(T (&a)[N], int n){
//     for(int i = 0; i < N; ++i){
//         a[i] = n;
//         n++;
//     }
//     return 0;
// }

// template<typename T, size_t N>
// int init_array(T (&a)[N], int n, int j){
//     for(int i = 0; i < N; ++i){
//         a[i] = n;
//         n = n+3;
//     }
//     return 0;
// }


template <typename... Args>
std::tuple<Args...> make_tuple(Args&&... args) {
    return std::tuple<Args...>(std::forward<Args>(args)...);
}

template<typename T, size_t N, typename ...Args>
int init_array(T (&a)[N], Args... arg){
    if(sizeof...(arg) == 0){    
    for(int i = 0; i < N; ++i){
            a[i] = i;
        }
    }
    else if(sizeof...(arg) == 1){
    for(int i = 0; i < N; ++i){

        auto my_tuple = make_tuple(Args ...arg);
        cout << std::get<0>(my_tuple);
        // std::get<0>(my_tuple)++;
        }
    }

    return 0;

}