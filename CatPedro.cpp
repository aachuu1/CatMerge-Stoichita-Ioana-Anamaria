#include "CatPedro.h"
#include "raylib.h"

// Constructor
CatPedro::CatPedro(int x, int y) : Cat(x, y), radius_pedro(35), index_pedro(0) {}

// Draw method
void CatPedro::Draw() {
    DrawCircle(x, y, radius_pedro, BLUE);
}

// Update method
void CatPedro::Update() {
    bool ajunsSol = (y >= 600 - radius_pedro);
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
            if (y > 600 - radius_pedro) {
                y = 600 - radius_pedro;
                isFalling = false;
            }
        }
        if (x > 415 - radius_pedro) {
            x = 415 - radius_pedro;
        }
        if (x < 70 - radius_pedro) {
            x = 70 - radius_pedro;
        }
    }
}

// Clone method
std::shared_ptr<Cat> CatPedro::clone() const {
    return std::make_shared<CatPedro>(*this);
}

// Check if cat has reached the ground
bool CatPedro::hasReachedGround() const {
    return y == 600 - radius_pedro;
}

// Get index of the cat
int CatPedro::GetIndexCat() const {
    return index_pedro;
}

// Static method to show Pedro info
void CatPedro::ShowPedro() {
    std::cout << "The current cat is Pedro\n";
}

// Override for printing cat-specific info
void CatPedro::PrintInfo() const {
    std::cout << "CatPedro Info: Position(" << x << ", " << y << "), Radius: " << radius_pedro << "\n";
}
