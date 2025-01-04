#include <raylib.h>
#include "CatHoratiu.h"
//function that deals with the cats movement, the left, right and bottom boundaries
void CatHoratiu::Update(){
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
//function to draw "cat", a circle for now
void CatHoratiu::Draw(){
    DrawCircle(x ,y ,radius_horatiu, PINK);
}
//bool function to determine if the cat has reached ground
bool CatHoratiu::hasReachedGround() const {
    return y==600-radius_horatiu;
}
//function for dynamic_cast
void CatHoratiu::ShowHoratiu() {
    std::cout<<"The current cat is Horatiu"<< std::endl;
}

int CatHoratiu::GetIndexCat() const {
    return index_horatiu;
}

