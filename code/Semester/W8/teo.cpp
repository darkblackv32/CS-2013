#include <iostream>
#include <thread>

void foo(){
    std::cout << "funcion 'foo'\n";
}

int main(){
    std::thread t(&foo);
    std::cout << "funcion 'main'\n";
    t.join();
return 0;
}