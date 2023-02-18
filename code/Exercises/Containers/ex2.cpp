#include <iostream>
#include <list>
#include <random>
#include <algorithm>
#include <unordered_set>
using namespace std;

template<typename T>
std::list<T> gen_list(){
    list<T> lt;
    mt19937 generator(std::random_device{}());  
    uniform_int_distribution<T> distribution(1, 50);
    for(int i = 0; i < 500; i++){
      lt.push_back(distribution(generator));
  }
  return lt; 
} 

void del_rep(std::list<int> &list) {

  std::unordered_set<int> set;

  for (auto it = list.begin(); it != list.end();) {
    // Check if the current element is already in the set
    if (set.count(*it)) {
      // If it is, delete the element from the list
      it = list.erase(it);
    } else {
      // If it isn't, add the element to the set and move
      set.insert(*it);
      ++it;
    }
  }
}

int main(){

  list<int> lit = gen_list<int>();

  lit.sort();  //? activate if you wanna sort after delete the repetitions
 
  del_rep(lit);

  for (int i : lit) {
    std::cout << i << " ";
  }

    return 0;
}
