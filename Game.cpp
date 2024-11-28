#include "Game.h"
#include "Boundary.h"
#include "Cat.h"
#include <bits/stdc++.h>

Game* Game::instance = nullptr;

Game::Game(){
    InitWindow(600, 600, "CatMerge");
    SetTargetFPS(60);
    font = LoadFontEx("Font/monogram.ttf", 64, nullptr, 0);
    cats.push_back(Cat());
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
        score.SetScore();
        Boundary::Draw();
        for (int i = 0; i < cats.size(); i++) {
            cats[i].Draw();
            cats[i].Update();
            if (cats[i].hasReachedGround()) {
                if (i==cats.size()-1) {
                    cats.push_back(Cat());
                }
                score.UpdateScore(100);
            }
        }
        score.DrawScore();
        EndDrawing();
    }
}

Score Game::GetScore() const {
    return this->score;
}

Boundary Game::GetBoundary() const {
    return this->boundary;
}

