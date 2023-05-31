#include <iostream>
using namespace std;

// SINGLETON 
class Logger {
public:
    // Atributo estático para almacenar la instancia única
    static int x;
    static Logger* instance;
    static Logger getInstance(){

        if(instance == nullptr){
            instance = new Logger();
        }
        return *instance;

    }

    void log(const std::string& message) {
        // Implementar la lógica para imprimir el mensaje en la consola
        cout << message << endl;
    }
private:
    Logger() {} // Constructor privado para evitar la creación de instancias
};

// Inicialización del atributo estático
Logger* Logger::instance = nullptr;


int main() {
    Logger logger = Logger::getInstance();
    logger.log("Este es un mensaje de prueba.");
	
	// Resultado esperado en consola:
	//
	// Este es un mensaje de prueba.

    return 0;
}
