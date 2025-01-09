#include "CatHoratiu.h"
#include <iostream>
#include "raylib.h"

// constructor initializing the position, radius, and index
CatHoratiu::CatHoratiu(int x, int y) : Cat(x, y), radius_horatiu(25), index_horatiu(1) {}

// draws the cat as a red circle
void CatHoratiu::Draw() {
    DrawCircle(x, y, radius_horatiu, RED);
}

// updates the cat's position and handles movement and gravity
void CatHoratiu::Update() {
    bool ajunsSol = (y >= 600 - radius_horatiu); // checks if the cat reached the ground
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
            if (y > 600 - radius_horatiu) { // stop at ground level
                y = 600 - radius_horatiu;
                isFalling = false;
            }
        }
        if (x > 415 - radius_horatiu) { // restrict movement within right boundary
            x = 415 - radius_horatiu;
        }
        if (x < 70 - radius_horatiu) { // restrict movement within left boundary
            x = 70 - radius_horatiu;
        }
    }
}

// clones the current CatHoratiu object
std::shared_ptr<Cat> CatHoratiu::clone() const {
    return std::make_shared<CatHoratiu>(*this);
}

// checks if the cat has reached the ground
bool CatHoratiu::hasReachedGround() const {
    return y == 600 - radius_horatiu;
}

// returns the index of the cat
int CatHoratiu::GetIndexCat() const {
    return index_horatiu;
}

// prints a message indicating the cat's identity
void CatHoratiu::ShowHoratiu() {
    std::cout << "The current cat is Pedro\n";
}

// prints detailed information about the cat
void CatHoratiu::PrintInfo() const {
    std::cout << "CatPedro Info: Position(" << x << ", " << y << "), Radius: " << radius_horatiu << "\n";
}
