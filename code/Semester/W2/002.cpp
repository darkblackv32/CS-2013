#include <iostream>

using namespace std;

class Deck{
friend ostream& operator<<(ostream& os, const Deck& deck);
private:
    int deck[52];
    int random;
public:
    Deck();
    void operator>>(int random);
};

Deck::Deck(){
    cout << "Creando baraja..." << endl;
    for(int i = 0; i < 52; i++){
        deck[i] = i;
        cout << deck[i] << " ";
    }
    cout << endl;
}

void Deck::operator>>(int random){
    cout << "Barajando..." << endl;
    for(int i = 0; i < random; i++){
        int j = rand() % 52;
        int k = rand() % 52;
        int temp = deck[j];
        deck[j] = deck[k];
        deck[k] = temp;
    }
}

ostream& operator<<(ostream& os, const Deck& deck){
    int i = rand() % 52;
    int j = rand() % 52;
    os << "----------------------------------------" << endl;
    os << "Carta 1: " << deck.deck[i] << endl;
    os << "Carta 2: " << deck.deck[j] << endl;
    os << "----------------------------------------" << endl;
    if(deck.deck[i] == deck.deck[j])
        os << "Ganaste!" << endl;
    else
        os << "Perdiste!" << endl;
    return os;
}

int main(){
    Deck deck;
    int barajar;
    cout << "Barajar? (1 o mas): ";
    cin >> barajar;
    if(barajar >= 1){
        deck >> barajar;
        cout << deck;
    }
}