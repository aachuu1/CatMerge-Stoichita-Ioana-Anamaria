#include "Game.h"
#include <random>
#include "CatHoratiu.h"
#include "CatPedro.h"
#include "CatPandispan.h"
#include "Exceptions.h"
//static instance pointer
Game* Game::instance = nullptr;
//constructor to initialize game window, cats and font
Game::Game() {
    InitWindow(600, 600, "CatMerge");
    SetTargetFPS(60);
    font = LoadFontEx("Font/monogram.ttf", 64, nullptr, 0);
    CheckFontLoaded();
    cats.push_back(std::make_unique<CatPedro>());
}
//destructor to unload the font and close the window
Game::~Game() {
    UnloadFont(font);
    CloseWindow();
}
//function for game instance
Game& Game::GetInstance() {
    if (instance == nullptr) {
        instance = new Game();
    }
    return *instance;
}
//function for game loop and exception handling
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
            //missing font exception
            BeginDrawing();
            ClearBackground(RED);
            std::cout<<ex.what();
            EndDrawing();
        }catch (const InvalidKeyException& ex1) {
            //invalid key exception
            BeginDrawing();
            ClearBackground(RED);
            DrawText(ex1.what(), 100, 300, 20, BLACK);
            EndDrawing();
        } catch (const KeyNotFoundException& ex2) {
            //no key exception
            BeginDrawing();
            ClearBackground(WHITE);
            DrawText(ex2.what(), 100, 300, 10, BLACK);
            EndDrawing();
        }
    }
}
//function for checking if the wrong key is pressed
void Game::CheckForInvalidKeyPress() {
    for (int key = 0; key < 350; key++) {
        if (IsKeyDown(key) && key != KEY_LEFT && key != KEY_RIGHT) {
            throw InvalidKeyException();
        }
    }
}
//function for checking if no key is pressed
void Game::CheckNoKeyPress() {
    if (!IsKeyDown(KEY_LEFT) && !IsKeyDown(KEY_RIGHT)) {
        throw KeyNotFoundException();
    }
}
//function for checking if the font has loaded
void Game::CheckFontLoaded() const {
    if(font.texture.id==0) {
        throw FontNotDetectedException();
    }
}
//function for spawning cats (we spawn cats, update them and then check if the previous cat has reached ground, if it has we spawn a random on).
void Game::UpdateCats() {
    for (int i = 0; i < cats.size(); i++) {
        cats[i]->Draw();
        cats[i]->Update();
        if (cats[i]->hasReachedGround()) {
            if (i == cats.size() - 1) {
                AddNewCat();
                score.UpdateScore(200);
            }
        }
        //needed to use dynamic_cast :p
        // if (auto pedroCat = dynamic_cast<CatPedro*>(cats[i].get())) {
        //     pedroCat->ShowPedro();
        // }
        // if (auto pandsipanCat = dynamic_cast<CatPandispan*>(cats[i].get())) {
        //     pandsipanCat->ShowPandispan();
        // }
        // if (auto horatiuCat = dynamic_cast<CatHoratiu*>(cats[i].get())) {
        //     horatiuCat->ShowHoratiu();
        // }
    }
}
//function to spawn a new cat(we pick a random number from 0 to 2 and based on that number spawn a certain cat).
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
//function the game UI, handles boundary also.
void Game::DrawUI() const {
    DrawRectangleRounded({415, 0, 300, 600}, 0, 6, LIGHTGRAY);
    DrawTextEx(font, "Score", {460, 15}, 38, 2, BLACK);
    DrawRectangleRounded({425, 55, 170, 60}, 0.3, 6, PINK);
    Boundary::Draw();
}
//getter for score
const Score& Game::GetScore() const {
    return score;
}
//getter for boundary
Boundary Game::GetBoundary() const {
    return boundary;
}
