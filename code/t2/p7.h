#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <map>

using namespace std;

// template <typename T>
// std::ostream& operator<<(std::ostream& os,  list<T> &container) {
//     for (const auto& item : container) {
//         os << item << " ";
//     }
//     return os;
// }

namespace std {
    template <typename T, size_t N>
    std::ostream& operator<<(std::ostream& os, array<T, N>array) {
        for(int i = 0; i < N; ++i) {
            os << array[i] << " ";
        }
        return os;
    }
}
