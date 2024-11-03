#include <stdio.h>
#include "Cat.h"
#include <vector>
#include <raylib.h>
#include "Boundary.h"


//clasa singleton pentru joc pe care sa o apelez o singura data

int main() {
    InitWindow(600, 600, "CatMerge");
    SetTargetFPS(60);
    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);
    std::vector<Cat> pisica1;
    pisica1.push_back(Cat());
    Cat pisica;
    Boundary linie;
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        DrawRectangleRounded({415, 0, 300, 600}, 0, 6, LIGHTGRAY);
        DrawTextEx(font,"Score", {460, 15}, 38, 2, BLACK);
        DrawTextEx(font,"Next", {460, 175}, 38, 2, BLACK);
        DrawRectangleRounded({425, 55, 170, 60}, 0.3, 6, PINK);
        DrawRectangleRounded({425, 215, 170, 180}, 0.3, 6, PINK);
        linie.Draw();
        pisica.Draw();
        pisica.Update();
        EndDrawing();
    }
    CloseWindow();
}
