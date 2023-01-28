#include <type_traits>
#include <vector>
#include <iostream>
using namespace std;


// template <typename T, typename S>
// bool are_same(){
//     return std::is_same<T,S>::value;
// }


// template <typename T, typename S>
// bool are_same(){
//     bool value = is_same<T, S>::value;
//     return value;
// }

// template <typename U>
// bool are_same(){
//     return true;
// } esto causaba ambiguedad

// template <typename T, typename ...Args>
// bool are_same(){
//     static constexpr bool value = std::disjunction<std::is_same<T, Args>...>::value;
//     // if (Args = {}){return true;}
//     // else
//     return value;
// }


template <typename T, typename ...Args>
bool are_same(){
    static constexpr bool value = std::disjunction<std::is_same<T, Args>...>::value;
    int arg = sizeof...(Args);
    if(arg == 0){
        return true;
    }
    else
        return value;
}

// ? std::is_same
//* If T and U name the same type (taking into account const/volatile qualifications), provides 
// *the member constant value equal to true. Otherwise value is false.


// ? std::is_disjuction
//* // ? std::is_same
		
// ? Forms the logical disjunction of the type traits B..., effectively performing a logical OR on
//?  the sequence of traits.
// basicamente compara los T con los F con un OR, para ver cual queda, y luego sigue iterando con los otros Args del variadic





// template <typename T, typename ...Args>
// bool are_same(){
//     static constexpr bool value = std::is_same<T, T>::value;
//     static constexpr bool val = std::disjunction<std::is_same<T, Args>...>::value;
//     if(value == true){
//         return true;
//     }
//     else    
//         return val;
// }
   
      
      
