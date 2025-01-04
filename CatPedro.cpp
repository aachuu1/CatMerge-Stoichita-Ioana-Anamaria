#include <raylib.h>
#include "CatPedro.h"
//function that deals with the cats movement, the left, right and bottom boundaries
void CatPedro::Update(){
    bool ajunsSol = (y >= 600 - radius_pedro);
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
            if (y > 600 - radius_pedro) {
                y = 600 - radius_pedro;
                isFalling = false;
            }
        }
        if (x > 415 - radius_pedro) {
            x = 415 - radius_pedro;
            isFalling = false;
        }
        if (x < 70 - radius_pedro) {
            x = 70 - radius_pedro;
            isFalling = false;
        }
    }
}
//function to draw "cat", a circle for now
void CatPedro::Draw(){
    DrawCircle(x,y,radius_pedro, BLUE);
}
//function for dynamic_cast
void CatPedro::ShowPedro() {
    std::cout<<"The current cat is Pedro"<< std::endl;
}

int CatPedro::GetIndexCat() const {
    return index_pedro;
}

//bool function to determine if the cat has reached ground
bool CatPedro::hasReachedGround() const {
    return y == 600 - radius_pedro;
}

