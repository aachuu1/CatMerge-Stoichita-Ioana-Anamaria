#include "Game.h"

Game* Game::instance = nullptr;
Game& Game::GetInstance(){
    if(instance==nullptr){
        instance = new Game();
    }
    return *instance;
}
Game::~Game() {
    UnloadFont(font);
    CloseWindow();
}

void Game::Run() {
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        DrawRectangleRounded({415, 0, 300, 600}, 0, 6, LIGHTGRAY);
        DrawTextEx(font, "Score", {460, 15}, 38, 2, BLACK);
        DrawTextEx(font, "Next", {460, 175}, 38, 2, BLACK);
        DrawRectangleRounded({425, 55, 170, 60}, 0.3, 6, PINK);
        DrawRectangleRounded({425, 215, 170, 180}, 0.3, 6, PINK);
        Boundary::Draw();
        for (auto& cat : cats) {
            cat.Draw();
            cat.Update();
        }
        EndDrawing();
    }
}


