#include <iostream>

using namespace std;

class Complejo{
friend ostream& operator<<(ostream& os, const Complejo& complejo);
friend istream& operator>>(istream& is, Complejo& complejo);
private:
    int real;
    int imaginario;
public:
    Complejo(): real(0), imaginario(0){};
    Complejo(int r, int i): real(r), imaginario(i){};
    Complejo operator+(Complejo& complejo);
    Complejo operator-(Complejo& complejo);
    Complejo operator*(Complejo& complejo);
    bool operator==(Complejo& complejo);
    
    void operator++(){
        real++;
        imaginario++;
    };
};

Complejo Complejo::operator+(Complejo& complejo){
    return Complejo(real + complejo.real, imaginario + complejo.imaginario);
}

Complejo Complejo::operator-(Complejo& complejo){
    return Complejo(real - complejo.real, imaginario - complejo.imaginario);
}

Complejo Complejo::operator*(Complejo& complejo){
    return Complejo(real * complejo.real, imaginario * complejo.imaginario);
}

bool Complejo::operator==(Complejo& complejo){
    return (real == complejo.real && imaginario == complejo.imaginario);
}



ostream& operator<<(ostream& os, const Complejo& complejo){
    os << complejo.real << " + " << complejo.imaginario << "i";
    return os;
}

istream& operator>>(istream& is, Complejo& complejo){
    cout << "Ingrese el real: ";
    is >> complejo.real;
    cout << "Ingrese el imaginario: ";
    is >> complejo.imaginario;
    return is;
}

int main(){
    Complejo complejo1(1, 2);
    Complejo complejo2(3, 4);
    Complejo complejo3;
    cin >> complejo3;

    cout << "Complejo 1: " << complejo1 << endl;
    cout << "Complejo 2: " << complejo2 << endl;
    cout << "Complejo 3: " << complejo3 << endl;
    cout << "Complejo 1 + Complejo 2: " << complejo1 + complejo2 << endl;
    cout << "Complejo 1 - Complejo 2: " << complejo1 - complejo2 << endl;
    cout << "Complejo 1 * Complejo 2: " << complejo1 * complejo2 << endl;
    cout << "Complejo 1 == Complejo 2: " << (complejo1 == complejo2) << endl;
    cout << "Complejo 1 == Complejo 3: " << (complejo1 == complejo3) << endl;
    cout << "Complejo 1++: " <<endl;
    ++complejo1;
    cout << "Complejo 1: " << complejo1 << endl;
    cout << "Complejo 2: " << complejo2 << endl;
    cout << "Complejo 3: " << complejo3 << endl;
    cout << "Ingrese un complejo: ";
    cin >> complejo3;
    cout << "Complejo 3: " << complejo3 << endl;
    return 0;
}



int main (){

    Complejo complejo1 (1 , 2);
    Complejo complejo2 (3 , 4);
    Complejo complejo3;

    cin >> complejo3;

    cout << " complejo1 : " << complejo1 << endl ;
    cout << " complejo2 : " << complejo2 << endl ;
    cout << " complejo3 : " << complejo3 << endl ;

    // cout << " complejo1 + complejo2 : " ;
    cout << complejo1 + complejo2 << endl;

    Complejo c3 = complejo1 + complejo2;

    cout << c3;

    ++ complejo1 ;
    return 0;

}