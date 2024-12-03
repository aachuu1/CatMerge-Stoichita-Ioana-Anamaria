#include <raylib.h>
#include "CatPandispan.h"
//function that deals with the cats movement, the left, right and bottom boundaries
void CatPandispan::Update(){
    bool ajunsSol = (y >= 600 - radius_pandispan);
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
            if (y > 600 - radius_pandispan) {
                y = 600 - radius_pandispan;
                isFalling = false;
            }
        }
        if (x > 415 - radius_pandispan) {
            x = 415 - radius_pandispan;
            isFalling = false;
        }
        if (x < 60 - radius_pandispan) {
            x = 60 - radius_pandispan;
            isFalling = false;
        }
    }
}
//function to draw "cat", a circle for now
void CatPandispan::Draw(){
    DrawCircle(x ,y ,radius_pandispan, RED);
}
//function for dynamic_cast
void CatPandispan::ShowPandispan() {
    std::cout<<"The current cat is Pandispan"<< std::endl;
}
//bool function to determine if the cat has reached ground
bool CatPandispan::hasReachedGround() const {
    return y==600-radius_pandispan;
}