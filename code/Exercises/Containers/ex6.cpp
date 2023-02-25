#include <iostream>
#include <forward_list>
#include <random>

using namespace std;

template<typename T>
ostream& operator<<(ostream& os, forward_list<T>& fl){
    for (int& a : fl)
        os << a << " ";
    os << endl;
    return os;
}

void ran_num(forward_list<int>& f1){

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 100);
    
    for (int i = 0; i < 100; ++i) {
        f1.push_front(dis(gen));
    }
}

int main(){

    forward_list<int> f1;
    
    ran_num(f1);

    f1.remove_if([](int x){if (x <= 1) {
        return true;
    }
    for (int i = 2; i <= std::sqrt(x); ++i) {
        if (x % i == 0) {
            return true;
        }
    }
    return false;});

    cout << f1;

    cout << "number of elements : " << distance(f1.begin(),f1.end()) << endl ;

    return 0;
}