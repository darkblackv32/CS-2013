#include <iostream>
using namespace std;

template<class T = int>
class range
{
private:
    T min;
    T max;
    T step;
public:
    range(T min, T max, T step) {
        this->min = min;
        this->max = max;
        this->step = step;
    }
    void print(){
        for (T i = min; i <= max; i+= step)
        {
            cout << i << " ";
        }
        cout << endl;
        
    }

    ~range() {}
};






int main(){


    range<int> obj (1, 10, 1);
    obj.print();


    return 0;
}