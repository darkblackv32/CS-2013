#include "c2.h"
using namespace std;
// using namespace soldi;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vint;
typedef deque<int> dint;

template<class T>
void PRINT_VEC(vector<T> &v) { cout << "[ "; for (auto el : v) cout << el << " "; cout << "]"; }

int main() 
{
    vll num {1LL, 0LL, ll(1e9), ll(1e5 + 10)};
    cout<<"interesting numbers -> "<<1e5+((1e5-1)*1e5)/2<<endl;        // 5.00005e+09 = 5000050000
    
    // STL
    vint v1(5, -2);
    cout<<"vector<int> alias vint v1 -> ";
    PRINT_VEC(v1);
    cout<<endl;

    dint d1;
    d1.push_front(1);
    d1.push_back(2);

    d1[0] = 5;
    cout<<"deque<int> alias dint d1 -> [ ";
    for (int i=0; i<d1.size(); ++i)
        cout<<d1[i]<<" ";
    cout<<"]\n";

    // MY NAMESPACE
    soldi::vint v2;
    v2 = soldi::vint(5, -2);
    cout<<"v2 -> ";
    cout<<v2<<endl;

    soldi::dint d2(4, 1);
    d2[2] = 2;

    cout<<"d2 -> [ ";
    for (int i=0; i<d2.sz(); ++i)
        cout<<d2[i]<<" ";
    cout<<"]\n";

    d2.copy_from_vint(v2);

    cout<<"v2 copy to d2 -> [ ";
    for (int i=0; i<d2.sz(); ++i)
        cout<<d2[i]<<" ";
    cout<<"]\n";

}