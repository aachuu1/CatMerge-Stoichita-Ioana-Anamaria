#include "Game.h"
#include <random>
#include "CatHoratiu.h"
#include "CatPedro.h"
#include "CatPandispan.h"
#include "Exceptions.h"

Game* Game::instance = nullptr;

Game::Game() {
    InitWindow(600, 600, "CatMerge");
    SetTargetFPS(60);
    font = LoadFontEx("Font/monogram.ttf", 64, nullptr, 0);
    CheckFontLoaded();
    cats.push_back(std::make_unique<CatPedro>());
    lastSpawnTime = GetTime();
}

Game::~Game() {
    UnloadFont(font);
    CloseWindow();
}

Game& Game::GetInstance() {
    if (instance == nullptr) {
        instance = new Game();
    }
    return *instance;
}

void Game::Run() {
    while (!WindowShouldClose()) {
        try {
            CheckForInvalidKeyPress();
            BeginDrawing();
            ClearBackground(WHITE);
            DrawUI();
            UpdateCats();
            score.DrawScore();
            CheckNoKeyPress();
            EndDrawing();
        } catch (const FontNotDetectedException& ex) {
            BeginDrawing();
            ClearBackground(RED);
            std::cout<<ex.what();
            EndDrawing();
        }catch (const InvalidKeyException& ex1) {
            BeginDrawing();
            ClearBackground(RED);
            DrawText(ex1.what(), 100, 300, 20, BLACK);
            EndDrawing();
        } catch (const KeyNotFoundException& ex2) {
            BeginDrawing();
            ClearBackground(WHITE);
            DrawText(ex2.what(), 100, 300, 10, BLACK);
            EndDrawing();
        }
    }
}

void Game::CheckForInvalidKeyPress() {
    for (int key = 0; key < 350; key++) {
        if (IsKeyDown(key) && key != KEY_LEFT && key != KEY_RIGHT) {
            throw InvalidKeyException();
        }
    }
}
void Game::CheckNoKeyPress() {
    if (!IsKeyDown(KEY_LEFT) && !IsKeyDown(KEY_RIGHT)) {
        throw KeyNotFoundException();
    }
}
void Game::CheckFontLoaded() const {
    if(font.texture.id==0) {
        throw FontNotDetectedException();
    }
}

void Game::UpdateCats() {
    for (int i = 0; i < cats.size(); i++) {
        cats[i]->Update();
        cats[i]->Draw();
        if (cats[i]->hasReachedGround()) {
            if (i == cats.size() - 1) {
                AddNewCat();
                score.UpdateScore(200);
            }
        }
        if (auto pedroCat = dynamic_cast<CatPedro*>(cats[i].get())) {
            pedroCat->ShowPedro();
        }
        if (auto pandsipanCat = dynamic_cast<CatPandispan*>(cats[i].get())) {
            pandsipanCat->ShowPandispan();
        }
        if (auto horatiuCat = dynamic_cast<CatHoratiu*>(cats[i].get())) {
            horatiuCat->ShowHoratiu();
        }
    }
}

void Game::AddNewCat() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 2);
    switch (dis(gen)) {
        case 0:
            cats.push_back(std::make_unique<CatPedro>());
        break;
        case 1:
            cats.push_back(std::make_unique<CatPandispan>());
        break;
        case 2:
            cats.push_back(std::make_unique<CatHoratiu>());
        break;
        default:
            cats.push_back(std::make_unique<CatPedro>());
        break;
    }
}

void Game::DrawUI() const {
    DrawRectangleRounded({415, 0, 300, 600}, 0, 6, LIGHTGRAY);
    DrawTextEx(font, "Score", {460, 15}, 38, 2, BLACK);
    DrawRectangleRounded({425, 55, 170, 60}, 0.3, 6, PINK);
    DrawText(("Numar pisici: " + std::to_string(cats.size())).c_str(), 10, 10, 20, BLACK);
    Boundary::Draw();
}

Score Game::GetScore() const {
    return score;
}

Boundary Game::GetBoundary() const {
    return boundary;
}
