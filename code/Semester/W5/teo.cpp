#include <iostream>
#include <algorithm>

using namespace std;

void ex1(), ex2(), ex22(), ex3(), ex33(), ex333(), ex4(), ex44(), ex5(), ex6();

/* ex1 : A Callable type is a type for which the INVOKE and INVOKE<R> operations 
(used by, e.g., function, bind, and thread::thread) are applicable.
! ex  : Functions,  pointer to function, functors and lambdas
*/ 

//* ex1
int add(int a, int b){
        return a + b;
}

/* ex2 : A callback is a programming concept where a function is passed as an
argument to another function, allowing it to be called (or "called back") at a later point in time.  
! ex : A function that is passed as an argument to another function is called a callback function. 
*/

//* ex2

int suma(int x1, int x2){return x1 + x2;}
int resta(int x1, int x2){return x1 - x2;}
int mult(int x1, int x2){return x1 * x2;}

void calculadora(int (*f)(int, int), int x1, int x2){
    cout << "El resultado es: " << f(x1, x2) << endl;
}

/* ex3 : Functors, also known as function objects, are objects that can be called as if they were functions.
In C++, this is achieved by defining a class or struct with an overloaded operator() (function call operator).*/


/* ex4: A lambda expression is an expression of the form 
[ capture ] ( params ) mutable(optional) exception attribute -> ret { body } .
A way to define anonymous functions (functions without a name) directly in your code 
! [=]: All the external variables of the body are captured by copy.
! [&]: All the external variables of the body are captured by reference. */ 

/*ex6 */
int fibonacci(int n){

    if(n<=2) return 1;
    return fibonacci(n-1) + fibonacci(n-2);

}

int main(){

    // ex1();
    // ex2();
    // ex22();
    // ex3();
    // ex333();
    ex4();
    // ex44();
    // ex5();
    // ex6();

    return 0;
}




void ex1(){
    
    int num1, num2, sum;

    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    sum = add(num1, num2);


    cout << "The sum of " << num1 << " and " << num2 << " is: " << sum << endl;
}

void ex2(){

    int x1 = 3, x2 = 2;
    calculadora(suma, x1, x2);
    calculadora(resta, x1, x2);
    calculadora(mult, x1, x2);

}

void ex22(){

    int x1 = 3, x2 = 2;
    
    // pointer to function
    int (*pf)(int, int);

    // assing function to pointer
    pf = suma;
    cout << "El resultado es: " << pf(x1, x2) << endl;
    // assing function to pointer
    pf = resta;
    cout << "El resultado es: " << pf(x1, x2) << endl;
}

void ex3(){

    struct pow2{
        int operator()(int x){
            return x * x;
        }
    };

    int i = -5;
    pow2 powObj;
    int i2 = powObj(i);
    cout << i2 << endl;

}

void ex33(){

    struct printString{
        char _c;
        printString(char c = ' '): _c(c) {}
        void operator() (string s){
            cout << s << _c;
        }
    };

    printString line('\n');
    line("Hola");
    printString excl('!');
    excl("Ingrese un entero valido");

}

void ex333(){

    struct printString{
        char _c;
        printString(char c = ' '): _c(c) {}
        void operator() (string s){
            cout << s << _c;
        }
    };

    string v[4] = {"Hola","Mundo","en","C++"};

    for_each(v, v+4, printString('\n'));

}

void ex4(){

    struct C{
        int num = 0;
        void metodo(int x){
            auto f = [=]{this->num = x;};
            f();
        }          
    };


    C c;
    cout << "this->num = " <<c.num << endl;
    c.metodo(5);
    cout << "this->num = " <<c.num << endl;
}   


void ex44(){

    vector<int> v(5);

    generate(v.begin(), v.end(),[i=1]()mutable{return i*=2;});
    for_each(v.begin(),v.end(),[](int x){cout<< x << " ";});
    cout << endl;
}

void ex5(){

    vector<string> v = {"Hola","Mundo","en","C++"};

    for_each(v.begin(), v.end(), [](string s){cout << s << ' ';});
    cout << "\n---------------------------------\n";
    sort(v.begin(), v.end(),[](string s1, string s2){return s1.size() < s2.size();});
    for_each(v.begin(), v.end(), [](string s){cout << s << ' ';});
    cout << "\n---------------------------------\n";
}


void ex6(){

    

    vector<int> v = {1,2,3,4,5,6,7,8,9,10};

    transform(v.begin(), v.end(), v.begin(), fibonacci);
    for_each(v.begin(), v.end(), [](int x){cout << x << " ";});
    cout << "\n---------------------------------\n";

}

