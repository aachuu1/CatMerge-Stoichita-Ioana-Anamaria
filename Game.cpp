#include "Game.h"
#include <random>
#include <stdexcept>

class InvalidKeyException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Oh no, you pressed the wrong key!";
    }
};

Game* Game::instance = nullptr;


Game::Game() {
    InitWindow(600, 600, "CatMerge");
    SetTargetFPS(60);
    font = LoadFontEx("Font/monogram.ttf", 64, nullptr, 0);
    cats.push_back(std::make_unique<Cat>());
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

            EndDrawing();
        } catch (const InvalidKeyException& ex) {
            BeginDrawing();
            ClearBackground(WHITE);
            DrawText(ex.what(), 100, 300, 20, BLACK);
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

void Game::UpdateCats() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 3);

    for (int i = 0; i < cats.size(); i++) {
        cats[i]->Update();
        cats[i]->Draw();

        if (cats[i]->hasReachedGround()) {
            if (i == cats.size() - 1) {
                AddNewCat();
                score.UpdateScore(200);
            }
        }
    }
}

void Game::AddNewCat() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 3);

    switch (dis(gen)) {
        case 0:
            cats.push_back(std::make_unique<Cat>());
            break;
        case 1:
            cats.push_back(std::make_unique<CatPedro>());
            break;
        case 2:
            cats.push_back(std::make_unique<CatPandispan>());
            break;
        case 3:
            cats.push_back(std::make_unique<CatHoratiu>());
            break;
        default:
            cats.push_back(std::make_unique<Cat>());
            break;
    }
}

void Game::DrawUI() const {
    DrawRectangleRounded({415, 0, 300, 600}, 0, 6, LIGHTGRAY);
    DrawTextEx(font, "Score", {460, 15}, 38, 2, BLACK);
    DrawRectangleRounded({425, 55, 170, 60}, 0.3, 6, PINK);
    DrawText(("Număr pisici: " + std::to_string(cats.size())).c_str(), 10, 10, 20, BLACK);
    Boundary::Draw();
}

Score Game::GetScore() const {
    return score;
}

Boundary Game::GetBoundary() const {
    return boundary;
}
