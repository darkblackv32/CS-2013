#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <iomanip>
#include <assert.h>

using namespace std;


void checksum(vector<int> C){
    for (const int e: C)
        assert(e==3);
}

void sum(vector<int> a, vector<int> b, vector<int> &c, int chunk, int chunks){
    int in = chunk * (a.size()/chunks);
    int fin = (chunk + 1) * (a.size()/chunks);

    for (size_t i = 0; i < a.size(); i++)
    {
        c[i] = a[i] + b[i];
    }
    
}


int main(){

    chrono::time_point<std::chrono::system_clock> t_inicio, t_final;

    vector<int> a(1000000, 1);
    vector<int> b(1000000, 2);
    vector<int> c(1000000, 0);

    t_inicio = chrono::high_resolution_clock::now();
    thread t1 (&sum, a, b, ref(c), 0, 2);
    thread t2 (&sum, a, b, ref(c), 1, 2);

    t1.join();
    t2.join();

    t_final = chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> t = t_final - t_inicio;
    std::cout << "Tiempo = " << std::fixed << std::setprecision(5) << t.count() << "ms" << std::endl;

    // checksum(c); 




    return 0;
}