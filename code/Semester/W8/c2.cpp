#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>
#include <chrono>

using namespace std;

void dot(vector<double> v1, vector<double> v2, double& res, int chunk, int chunks){
    int inicio = chunk * (v1.size()/chunks);
    int fin = (chunk + 1) * (v1.size()/chunks);

    for (int i=inicio; i < fin; i++)
        res += v1[i] * v2[i];
}

int main(){
    int N = 10000000000000;
    vector<double> v1(N);
    vector<double> v2(N);

    generate(v1.begin(), v1.end(), [](){return (double)rand()/RAND_MAX;});
    generate(v2.begin(), v2.end(), [](){return (double)rand()/RAND_MAX;});

    int nthreads = thread::hardware_concurrency();
    cout << "nthreads = " << nthreads << endl;
    chrono::time_point<std::chrono::system_clock> t_inicio, t_final;

    vector<thread> threads;
    double res = 0.;

    t_inicio = chrono::high_resolution_clock::now();
    for (int i=0; i < nthreads; i++){
        threads.push_back(thread(&dot, v1, v2, ref(res), i, nthreads));
    }

    for (int i=0; i < nthreads; i++){
        threads[i].join();
    }

    t_final  = chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> t = t_final - t_inicio;

    cout << "Tiempo = " << t.count() << "ms" << endl;
}