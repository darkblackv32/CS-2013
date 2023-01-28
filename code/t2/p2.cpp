#include "p2.h"

int main(){
    std::vector<int> container = {10, 20, 30, 40, 50, 60};       // double ended queue (FIFO)
    int size = distance(container.begin(), container.end());
    // Imprimir en consola
    print(begin(container), end(container), std::cout, "-");
    // Grabarlos en un archivo
    std::ofstream file("out.txt");
    print(begin(container), end(container), file, "|");
    // Imprimir la mitad de valores
    auto last_it = next(begin(container), size / 2);
    print(begin(container), last_it, std::cout, "-");

    
}