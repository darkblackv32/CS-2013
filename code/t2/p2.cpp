#include "p2.h"

int main(){
    // Vector
    std::vector<int> vec = {10, 20, 30, 40, 50, 60};
    // Imprimir en consola
    print(begin(vec), end(vec), std::cout, "-");
    // Grabarlos en un archivo
    std::ofstream file("out.txt");
    print(begin(vec), end(vec), file, "|");
    // Imprimir la mitad de valores
    auto last_it = next(begin(vec), vec.size() / 2);
    print(begin(vec), last_it, std::cout, "-");

    
}