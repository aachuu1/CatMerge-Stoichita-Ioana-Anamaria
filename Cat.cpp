#include "Cat.h"
#include <iostream>
#include <raylib.h>
//constructor
Cat::Cat() : gravity(3), speed(5), isFalling(false), index(1), x(200), y(10), radius(20) {}
//getter for x
int Cat::getX() const {
    return x;
}
//getter for y
int Cat::getY() const {
    return y;
}
//getter for radius
int Cat::getRadius() const {
    return radius;
}
//destructor
Cat::~Cat() {
    std::cout << "Pisica a explodat" << std::endl;
};
//bool function to determine if the cat has reached ground
bool Cat::hasReachedGround() const {
    return y == 600 - radius;
}
//function to draw "cat", a circle for now
void Cat::Draw() {
    DrawCircle( x, y, radius, PINK);
}
//function that deals with the cats movement, the left, right and bottom boundaries
void Cat::Update() {
    bool ajunsSol = (y >= 600 - radius);
    if (!ajunsSol) {
        if (IsKeyDown(KEY_LEFT)) {
            x = x - speed;
            isFalling = false;
        }
        if (IsKeyDown(KEY_RIGHT)) {
            x = x + speed;
            isFalling = false;
        }
        if (!IsKeyDown(KEY_LEFT) && !IsKeyDown(KEY_RIGHT)) {
            isFalling = true;
        }
        if (isFalling) {
            y = y + gravity;
            if (y > 600 - radius) {
                y = 600 - radius;
                isFalling = false;
            }
        }
        if (x > 415 - radius) {
            x = 415 - radius;
            isFalling = false;
        }
        if (x < 40 - radius) {
            x = 40 - radius;
            isFalling = false;
        }
    }
}




