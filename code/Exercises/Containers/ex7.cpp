#include <iostream>
#include <forward_list>
using namespace std;

template<typename T>
ostream& operator<<(ostream& os, forward_list<T>& fl){
    for (auto it = fl.begin(); it != fl.end(); ++it) {
        os << *it << " ";
    }
    return os;
}


forward_list<string> foo(forward_list<string> fl, string st1, string st2){

    auto it = fl.begin();
    auto bef = fl.before_begin();
    bool flag = true;
    while(it != fl.end()){
        if(*it == st1)
        {
            // if(it != fl.end()){
            fl.insert_after(it++,st2);
            flag = false;
            // }
            // else
            //     bef = fl.insert_after(bef, st2);
        }
        it++;
    }
    //! FALTA COMPLETAR
    // fl.insert_after(fl.end(),st2);
    if (flag)
        fl.insert_after(next(fl.begin(), distance(fl.begin(), fl.end())-1), st2);
    return fl;
}

int main(){

    forward_list<string> f1 {"Software", "ML", "Crypto", "Cybersecurity", "Computer Architecture"};

    f1 = foo(f1, "ML", "Discrete Math");


    cout << f1;

    return 0;
}

/*

// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// typedef long double lb;
 
// const int mod = 1e9+7;
 
 
// template<typename T>
// void print(vector<T> &vec){
//     for(auto &x:vec) cout<<x<<' ';
//     cout<<'\n';
// }
 
// template<typename Q,typename W>
// void print(vector<pair<Q,W>> &vec){
//     for(auto &x:vec) cout<<x.first<<' '<<x.second<<'\n';
// }
 
// void barra(){ cout<<"--------------------"<<'\n';}
 
 
// int add(int x, int y) {
//     if (x + y >= mod)
//         return x + y - mod;
//     return x + y;
// }
 
// int sub(int x, int y) {
//     if (x - y < 0)
//         return x - y + mod;
//     return x - y;
// }
 
// int mul(int x, int y) {
//     return (long long) x * y % mod;
// }

// void solve(){
//     ll t;
//     cin>>t;
//     if (t & 1)
//         cout<<-1<<endl;
//     else
//         cout<<1<<" "<<t/2<<endl;
// }

// int main(){ 
// #ifndef TEST
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
// #endif
//   cin.tie(0);
//   ios::sync_with_stdio(0);
//   ll t=1;
//   cin>>t;
//   while(t--) solve();
// }
#include <iostream>
#include <forward_list>
using namespace std;

template<typename T>
ostream& operator<<(ostream& os, forward_list<T>& fl){
    for (auto it = fl.begin(); it != fl.end(); ++it) {
        os << *it << " ";
    }
    return os;
}


forward_list<string> foo(forward_list<string> fl, string st1, string st2){

    auto it = fl.begin();
    auto bef = fl.before_begin();
    bool flag = true;
    while(it != fl.end())     // si el siguiente del actual no es el siguiente al ultimo | si yo no soy el ultimo
    {
        if(*it == st1)
        {   
            // cout << *(it++) << " ";
            fl.insert_after(it, st2);
            // flag = false;
        }
        it++;
    }
    // if (flag)   // == true
    //     fl.insert_after(
    //         next(fl.begin(), distance(fl.begin(), fl.end())-1), 
    //         st2);
    cout<<endl;
    return fl;
}

int main(){

    forward_list<string> f1 {"Software", "ML", "ML", "Cybersecurity", "Computer Architecture"};

    f1 = foo(f1, "ML", "Discrete Math");


    cout << f1;

    return 0;

}


*/