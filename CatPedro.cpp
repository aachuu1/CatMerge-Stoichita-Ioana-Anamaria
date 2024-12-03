#include <raylib.h>
#include "CatPedro.h"

void CatPedro::Draw(){
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
        if (x < 40 - radius_pedro) {
            x = 40 - radius_pedro;
            isFalling = false;
        }
    }
}

void CatPedro::Update(){
    DrawCircle(x,y,radius_pedro, BLUE);
}
void CatPedro::ShowPedro() {
    std::cout<<"The current cat is Pedro"<< std::endl;
}