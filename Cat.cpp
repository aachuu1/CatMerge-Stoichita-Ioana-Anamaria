#include "Cat.h"

#include <iostream>

// constructor initializing position, radius, gravity, and speed
Cat::Cat(int x, int y) : x(x), y(y), radius(20), gravity(3.0f), speed(5.0f) {}

// destructor prints a message when the cat is destroyed
Cat::~Cat() {
    std::cout << "Pisica a explodat\n";
}

// getter for x-coordinate
int Cat::getX() const {
    return x;
}

// getter for y-coordinate
int Cat::getY() const {
    return y;
}

// getter for the radius
int Cat::getRadius() const {
    return radius;
}

// setter for x-coordinate
void Cat::setX(int newX) {
    x = newX;
}

// setter for y-coordinate
void Cat::setY(int newY) {
    y = newY;
}
