#include "CatPedro.h"
#include <iostream>
#include "raylib.h"

// constructor initializing position, radius, and index
CatPedro::CatPedro(int x, int y) : Cat(x, y), radius_pedro(35), index_pedro(0) {}

// draws the cat as a blue circle
void CatPedro::Draw() {
    DrawCircle(x, y, radius_pedro, BLUE);
}

// updates the cat's position and handles movement and gravity
void CatPedro::Update() {
    bool ajunsSol = (y >= 600 - radius_pedro); // checks if the cat reached the ground
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
            if (y > 600 - radius_pedro) { // stop at ground level
                y = 600 - radius_pedro;
                isFalling = false;
            }
        }
        if (x > 415 - radius_pedro) { // restrict movement within right boundary
            x = 415 - radius_pedro;
        }
        if (x < 70 - radius_pedro) { // restrict movement within left boundary
            x = 70 - radius_pedro;
        }
    }
}

// clones the current CatPedro object
std::shared_ptr<Cat> CatPedro::clone() const {
    return std::make_shared<CatPedro>(*this);
}

// checks if the cat has reached the ground
bool CatPedro::hasReachedGround() const {
    return y == 600 - radius_pedro;
}

// returns the index of the cat
int CatPedro::GetIndexCat() const {
    return index_pedro;
}

// prints a message indicating the cat's identity
void CatPedro::ShowPedro() {
    std::cout << "The current cat is Pedro\n";
}

// prints detailed information about the cat
void CatPedro::PrintInfo() const {
    std::cout << "CatPedro Info: Position(" << x << ", " << y << "), Radius: " << radius_pedro << "\n";
}
