#include <iostream>
using namespace std;

template <class T>
    class Pair{
        T _a, _b;
    public:
    Pair(T a, T b){
        _a = a;
        _b = b;
    }
    T Max();
};

template <class T>
T Pair<T>::Max () {
    return (_a > _b)? _a : _b;
}   

int main () {
    Pair<float> obj(1.3, 6.2);
    cout << obj.Max() << endl;
    return 0;
}