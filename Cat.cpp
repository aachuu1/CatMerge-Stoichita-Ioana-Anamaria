#include "Cat.h"

// Constructor
Cat::Cat(int x, int y) : x(x), y(y), radius(20), gravity(3.0f), speed(5.0f) {}

// Destructor
Cat::~Cat() {
    std::cout << "Pisica a explodat\n";
}

// Getters
int Cat::getX() const {
    return x;
}

int Cat::getY() const {
    return y;
}

int Cat::getRadius() const {
    return radius;
}

// Setters
void Cat::setX(int newX) {
    x = newX;
}

void Cat::setY(int newY) {
    y = newY;
}
