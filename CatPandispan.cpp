#include "CatPandispan.h"

#include <iostream>

#include "CatPedro.h"
#include "raylib.h"

// constructor initializing position, radius, and index
CatPandispan::CatPandispan(int x, int y) : Cat(x, y), radius_pandispan(20), index_pandispan(2) {}

// draws the cat as a pink circle
void CatPandispan::Draw() {
    DrawCircle(x, y, radius_pandispan, PINK);
}

// updates the cat's position and handles movement and gravity
void CatPandispan::Update() {
    bool ajunsSol = (y >= 600 - radius_pandispan); // checks if the cat reached the ground
    if (!ajunsSol) {
        if (IsKeyDown(KEY_LEFT)) { // move left
            x -= speed;
            isFalling = false;
        }
        if (IsKeyDown(KEY_RIGHT)) { // move right
            x += speed;
            isFalling = false;
        }
        if (!IsKeyDown(KEY_LEFT) && !IsKeyDown(KEY_RIGHT)) { // no movement keys pressed
            isFalling = true;
        }
        if (isFalling) { // apply gravity
            y += gravity;
            if (y > 600 - radius_pandispan) { // stop at ground level
                y = 600 - radius_pandispan;
                isFalling = false;
            }
        }
        if (x > 415 - radius_pandispan) { // restrict movement within right boundary
            x = 415 - radius_pandispan;
        }
        if (x < 70 - radius_pandispan) { // restrict movement within left boundary
            x = 70 - radius_pandispan;
        }
    }
}

// clones the current CatPandispan object
std::shared_ptr<Cat> CatPandispan::clone() const {
    return std::make_shared<CatPandispan>(*this);
}

// checks if the cat has reached the ground
bool CatPandispan::hasReachedGround() const {
    return y == 600 - radius_pandispan;
}

// returns the index of the cat
int CatPandispan::GetIndexCat() const {
    return index_pandispan;
}

// prints a message indicating the cat's identity
void CatPandispan::ShowPandispan() {
    std::cout << "The current cat is Pedro\n";
}

// prints detailed information about the cat
void CatPandispan::PrintInfo() const {
    std::cout << "CatPedro Info: Position(" << x << ", " << y << "), Radius: " << radius_pandispan << "\n";
}
