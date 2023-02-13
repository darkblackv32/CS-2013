#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

// TEO
// 1

template <typename T, int n>
vector<T> generate_random_vector() {
    vector<T> vector(n);
    mt19937 generator(std::random_device{}());  
    /*mt19937 is a class in the C++ Standard Library that implements a pseudo-random 
      number generator based on the Mersenne Twister algorithm. 
      std::random_device is a uniformly-distributed integer random number generator 
      that produces non-deterministic random numbers. */
    uniform_int_distribution<T> distribution(1, 10);
    //*generates random integers within a specified range


    //* fill the vector with random numbers
    for (int i = 0; i < n; i++) {
        vector[i] = distribution(generator);
    }

  return vector;
}

int main() {

    //? generating a random vector with type int, size 7 (we can change the size)
    vector<int> vector = generate_random_vector<int, 7>();
    std::vector<int> result;
    
    //? magic is here, we add each element to the vector result with a loop from 0 to the size of the num 
    //? (num == each element in the original vec) 
    for (int i = 0; i < vector.size(); i++) {
        int num = vector[i];
        for (int j = 0; j < num; j++) {
            result.push_back(num);
        }
    }

    //? finally, just using reverse we change the orden of elements in the vec result
    reverse(result.begin(), result.end());
    for (int i : result) {
        cout << i << " ";
    }

  return 0;
}