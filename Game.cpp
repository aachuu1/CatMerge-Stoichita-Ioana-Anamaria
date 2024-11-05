#include "Game.h"
#include "Boundary.h"

Game* Game::instance = nullptr;

Game::Game() : originalCat(), constructorCopiedCat(originalCat), operatorCopiedCat(originalCat) {
    InitWindow(600, 600, "CatMerge");
    SetTargetFPS(60);
    font = LoadFontEx("Font/monogram.ttf", 64, nullptr, 0);
    constructorCopiedCat.setX(300);
    constructorCopiedCat.setY(10);
    operatorCopiedCat.setX(300);
    operatorCopiedCat.setY(10);
}

Game& Game::GetInstance() {
    if (instance == nullptr) {
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
        DrawRectangleRounded({425, 55, 170, 60}, 0.3, 6, PINK);
        Boundary::Draw();
        originalCat.Draw();
        originalCat.Update();
        score.DrawScore();
        if (originalCat.hasReachedGround()) {
            constructorCopiedCat.Draw();
            constructorCopiedCat.Update();
            score.UpdateScore(100);
        }
        if (constructorCopiedCat.hasReachedGround()) {
            score.UpdateScore(100);
            operatorCopiedCat.Draw();
            operatorCopiedCat.Update();
        }
        if (operatorCopiedCat.hasReachedGround()) {
            score.UpdateScore(100);
        }
        EndDrawing();
    }
}
Score Game::GetScore() {
    return this->score;
}
