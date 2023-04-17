#include <iostream>
using namespace std;

template<class T>

class Numbers
{
private:
    T n1, n2;
public:

    Numbers(T _x, T _y) : n1{_x}, n2{_y}{}
    ~Numbers() {}

    T sum(){
        return n1+n2;
    }

    T res(){
        return n1-n2;
    }

    T mul(){
        return n1*n2;
    }

    T div(){
        return n1/n2;
    }

};

int main(void){

    Numbers n(2,5);

    cout << n.sum();

    return 0;
}
