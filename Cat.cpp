#include "Cat.h"
#include <iostream>
#include <raylib.h>

Cat::Cat() : x(200), y(10), gravity(3), speed(5), radius(20), isFalling(false) {}

int Cat::getX() const {
    return x;
}

int Cat::getY() const {
    return y;
}

void Cat::setX(int newX) {
    x = newX;
}

void Cat::setY(int newY) {
    y = newY;
}

Cat::~Cat() {
    std::cout << "Pisica a explodat" << std::endl;
};

bool Cat::hasReachedGround() const {
    return y == 600 - radius;
}

void Cat::Draw() const {
    DrawCircle( x, y, radius, PINK);
}

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


