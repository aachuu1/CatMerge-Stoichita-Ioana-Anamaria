#include "CatPandispan.h"

#include "CatPedro.h"
#include "raylib.h"

// Constructor
CatPandispan::CatPandispan(int x, int y) : Cat(x, y), radius_pandispan(20), index_pandispan(2) {}

// Draw method
void CatPandispan::Draw() {
    DrawCircle(x, y, radius_pandispan, PINK);
}

// Update method
void CatPandispan::Update() {
    bool ajunsSol = (y >= 600 - radius_pandispan);
    if (!ajunsSol) {
        if (IsKeyDown(KEY_LEFT)) {
            x -= speed;
            isFalling = false;
        }
        if (IsKeyDown(KEY_RIGHT)) {
            x += speed;
            isFalling = false;
        }
        if (!IsKeyDown(KEY_LEFT) && !IsKeyDown(KEY_RIGHT)) {
            isFalling = true;
        }
        if (isFalling) {
            y += gravity;
            if (y > 600 - radius_pandispan) {
                y = 600 - radius_pandispan;
                isFalling = false;
            }
        }
        if (x > 415 - radius_pandispan) {
            x = 415 - radius_pandispan;
        }
        if (x < 70 - radius_pandispan) {
            x = 70 - radius_pandispan;
        }
    }
}

// Clone method
std::shared_ptr<Cat> CatPandispan::clone() const {
    return std::make_shared<CatPandispan>(*this);
}

// Check if cat has reached the ground
bool CatPandispan::hasReachedGround() const {
    return y == 600 - radius_pandispan;
}

// Get index of the cat
int CatPandispan::GetIndexCat() const {
    return index_pandispan;
}

// Static method to show Pedro info
void CatPandispan::ShowPandispan() {
    std::cout << "The current cat is Pedro\n";
}

// Override for printing cat-specific info
void CatPandispan::PrintInfo() const {
    std::cout << "CatPedro Info: Position(" << x << ", " << y << "), Radius: " << radius_pandispan << "\n";
}
