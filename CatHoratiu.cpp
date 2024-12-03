#include <raylib.h>
#include "CatHoratiu.h"

void CatHoratiu::Draw(){
    bool ajunsSol = (y >= 600 - radius_horatiu);
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
            if (y > 600 - radius_horatiu) {
                y = 600 - radius_horatiu;
                isFalling = false;
            }
        }
        if (x > 415 - radius_horatiu) {
            x = 415 - radius_horatiu;
            isFalling = false;
        }
        if (x < 40 - radius_horatiu) {
            x = 40 - radius_horatiu;
            isFalling = false;
        }
    }
}

void CatHoratiu::Update(){
    DrawCircle(x ,y ,radius_horatiu, PINK);
}

void CatHoratiu::ShowHoratiu() {
    std::cout<<"The current cat is Horatiu"<< std::endl;
}