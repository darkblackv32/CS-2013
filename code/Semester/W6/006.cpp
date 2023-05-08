#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main(){
    srand((unsigned) time(NULL));

    vector<int> vec(20);

    generate(vec.begin(), vec.end(), [](){return rand()%20;});

    for_each(vec.begin(), vec.end(), [](int i){cout << i << " ";});

    cout << '\n';

    map<int, int> m1;

    for(int i = 0; i < vec.size(); i++)
        m1[vec[i]]++;

    //* another way
    // for(auto it = m1.begin(); it != m1.end(); it++)
    //     m1[*it]++;

    cout << endl;
    for (const auto &w: m1){
		cout << w.first << ": ";
		cout << w.second; 
	    cout << (w.second > 1 ? " veces": " vez") << endl;
	}

    cout << '\n';
    int elemento_repetido;
    int max_frecuencia;
    for (const auto& par : m1) {
        if (par.second > max_frecuencia) {
            max_frecuencia = par.second;
            elemento_repetido = par.first;
        }
    }

    //*antoher way

    // map<int,int>::iterator it = m1.begin();
    // pair<int,int> max_pair = {(*it).first, (*it).second};

    // for(auto it = m1.begin(); it != m1.end(); it++){
    //     if((*it).second > max_pair.second){
    //         max_pair = {(*it).first, (*it).second};
    //     }
    // }

    // cout << "El elemento que más se repite es: " << max_pair.first << endl;
    // cout << "Se repite " << max_pair.second << " veces." << endl;

     cout << "El elemento que más se repite es: " << elemento_repetido << endl;
    cout << "Se repite " << max_frecuencia << " veces." << endl;

    return 0;
}