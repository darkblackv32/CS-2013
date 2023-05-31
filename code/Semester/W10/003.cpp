#include <iostream>
using namespace std;

// Clase abstracta Character
    class Character {
    public:
        virtual std::string getInfo() = 0;
    };

    // Clase concreta NonPlayerCharacter
    class PlayerCharacter : public Character { // Clase concreta PlayerCharacter
    public:
        std::string getInfo() override {
        return "Personaje del jugador";
        }
    };

    class NonPlayerCharacter : public Character { // Clase concreta NonPlayerCharacter
    public:
        std::string getInfo() override {
        return "Personaje no jugador";
        }
    };

// Clase abstracta CharacterCreator
    class CharacterCreator {
    public:
        virtual Character* createCharacter() = 0;
    };

    class PlayerCharacterCreator : public CharacterCreator {
    public:
        Character* createCharacter() override {
        // Crear y retornar una instancia de PlayerCharacter
            return new PlayerCharacter();
        }
    };

    class NonPlayerCharacterCreator : public CharacterCreator {
        public:
        Character* createCharacter() override {
        // Crear y retornar una instancia de NonPlayerCharacter
            return new NonPlayerCharacter();
        }
};

int main() {

    CharacterCreator* creator = new NonPlayerCharacterCreator();
    Character* character = creator->createCharacter();
    // Completa el código para mostrar la información del personaje
    // Resultado esperado en la consola:
    // Información del personaje: Personaje del jugador

    cout << "Información del personaje: " << character->getInfo() << endl;

    delete character;
    delete creator;
    
    return 0;
}
