#include <iostream>
using namespace std;

// Abstract Factory

// Interfaz para las formas
    class Shape {
        public:
        virtual void draw() = 0;
    };
    // Clase concreta para el círculo
    class Circle : public Shape {
        public:
        void draw() override {
        std::cout << "Dibujando un círculo." << std::endl;
        }
    };
    // Clase concreta para el cuadrado
    class Square : public Shape {
        public:
        void draw() override {
        std::cout << "Dibujando un cuadrado." << std::endl;
        }
    };


    // Fábrica abstracta
    class ShapeFactory {
        public:
        virtual Shape* createShape() = 0;
    };

    class CircleFactory : public ShapeFactory {
        public:
        Shape* createShape() override {
        // TODO: Implementar la creación de un círculo
            return new Circle();
        }
    };

    class SquareFactory : public ShapeFactory {
        public:
        Shape* createShape() override {
        // TODO: Implementar la creación de un cuadrado
            return new Square();
        }
    };


    int main() {

    ShapeFactory* factory = new CircleFactory();
    // Implementar un circulo usando la fábrica
    Shape* shape = factory->createShape();
    shape->draw();
    // Resultado esperado:
    // Dibujando un círculo.
    delete shape;
    delete factory;

    return 0;
    }