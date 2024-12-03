#include <raylib.h>
#include "CatPandispan.h"

void CatPandispan::Draw(){
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
        if (x < 40 - radius_pandispan) {
            x = 40 - radius_pandispan;
            isFalling = false;
        }
    }
}

void CatPandispan::Update(){
    DrawCircle(x ,y ,radius_pandispan, RED);
}
void CatPandispan::ShowPandispan() {
    std::cout<<"The current cat is Pandispan"<< std::endl;
}