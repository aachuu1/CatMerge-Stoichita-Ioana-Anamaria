#include "CatHoratiu.h"
#include "raylib.h"

// Constructor
CatHoratiu::CatHoratiu(int x, int y) : Cat(x, y), radius_horatiu(25), index_horatiu(1) {}

// Draw method
void CatHoratiu::Draw() {
    DrawCircle(x, y, radius_horatiu, RED);
}

// Update method
void CatHoratiu::Update() {
    bool ajunsSol = (y >= 600 - radius_horatiu);
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
            if (y > 600 - radius_horatiu) {
                y = 600 - radius_horatiu;
                isFalling = false;
            }
        }
        if (x > 415 - radius_horatiu) {
            x = 415 - radius_horatiu;
        }
        if (x < 70 - radius_horatiu) {
            x = 70 - radius_horatiu;
        }
    }
}

// Clone method
std::shared_ptr<Cat> CatHoratiu::clone() const {
    return std::make_shared<CatHoratiu>(*this);
}

// Check if cat has reached the ground
bool CatHoratiu::hasReachedGround() const {
    return y == 600 - radius_horatiu;
}

// Get index of the cat
int CatHoratiu::GetIndexCat() const {
    return index_horatiu;
}

// Static method to show Pedro info
void CatHoratiu::ShowHoratiu() {
    std::cout << "The current cat is Pedro\n";
}

// Override for printing cat-specific info
void CatHoratiu::PrintInfo() const {
    std::cout << "CatPedro Info: Position(" << x << ", " << y << "), Radius: " << radius_horatiu << "\n";
}
