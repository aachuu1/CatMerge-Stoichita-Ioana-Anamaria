#include "Cat.h"
#include <iostream>
#include <raylib.h>

Cat::Cat() : x(200), y(10), radius(20), speed(5), gravity(3), isFalling(false) {}

int Cat::getX() const {
    return x;
}

int Cat::getY() const {
    return y;
}

Cat::~Cat() = default;

bool Cat::hasReachedGround() const {
    return y == 600 - radius;
}

void Cat::Draw() const {
    DrawCircle(x, y, radius, PINK);
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


