#include <iostream>

using namespace std;

// Clase Character con atributos
class Character {
public:
    std::string name;
    std::string type;
    int level;
    // Completa el código con más atributos relevantes para el personaje
    int health;
    void info() {
        cout << "Informacion del personaje:" << endl;
        cout << "Nombre: " << name << endl;
        cout << "Tipo: " << type << endl;
        cout << "Nivel: " << level << endl;
        cout << "Salud: " << health << endl;
        // Completa el código para mostrar más atributos relevantes para el personaje
    }
};

// Clase CharacterBuilder
class CharacterBuilder {
public:
    virtual void setName(const std::string& name) = 0;
    virtual void setType(const std::string& type) = 0;
    virtual void setLevel(int level) = 0;
    virtual void setHealth(int health) = 0;
    // Completa el código con métodos para configurar más atributos relevantes para el personaje
    virtual Character* getCharacter() = 0;
};

// Clase CharacterDirector
class CharacterDirector {
public:
    void constructCharacter(CharacterBuilder* builder) {
        builder->setName("Personaje");
        builder->setType("Tipo de personaje");
        builder->setLevel(1);
        builder->setHealth(100);
        // Completa el código para configurar más atributos relevantes para el personaje
    }
};

// Clase ConcreteCharacterBuilder
class ConcreteCharacterBuilder : public CharacterBuilder {
private:
    Character* character;
public:
    ConcreteCharacterBuilder() {
        character = new Character();
    }

    void setName(const std::string& name) override {
        character->name = name;
    }

    void setType(const std::string& type) override {
        character->type = type;
    }

    void setLevel(int level) override {
        character->level = level;
    }

    // Completa el código para configurar más atributos relevantes para el personaje
    void setHealth(int health) override {
        character->health = health;
    }
    Character* getCharacter() override {
        return character;
    }
};

int main() {
    CharacterBuilder* builder = new ConcreteCharacterBuilder();
    CharacterDirector director;
    director.constructCharacter(builder);
    Character* character = builder->getCharacter();

    // Completa el código para mostrar la información del personaje

    // Resultado esperado en la consola:
    // Información del personaje:
    // Nombre: Personaje
    // Tipo: Tipo de personaje
    // Nivel: 1
    // ...
    character->info();


    delete character;
    delete builder;

    return 0;
}