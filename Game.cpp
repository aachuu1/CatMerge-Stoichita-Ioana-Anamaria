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
    cats.push_back(std::make_unique<CatPedro>(200, 10));
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
    enum GameState { MENU, GAMEPLAY };
    GameState state = MENU;
    while (!WindowShouldClose()) {
        try {
            CheckForInvalidKeyPress();
            if (state == MENU) {
                BeginDrawing();
                Texture2D texture = LoadTexture("C:/Users/stoic/CLionProjects/CatMerge-Stoichita-Ioana-Anamaria/CatMergePoate/generated/assets/PhotoStart.png");
                DrawTexture(texture, 0, 0, WHITE);
                DrawText("Cat Merge", 100, 90, 80, BLACK);
                Rectangle startButton = { 200, 200, 170, 45 };
                Rectangle exitButton = { 200, 260, 170, 45 };
                Vector2 mousePoint = GetMousePosition();

                Color startColor = CheckCollisionPointRec(mousePoint, startButton) ? GRAY : WHITE;
                DrawRectangleRounded(startButton, 0.3, 6, startColor);
                DrawText("START", startButton.x + (startButton.width - MeasureText("START", 20)) / 2,
                         startButton.y + (startButton.height - 20) / 2, 20, BLACK);

                Color exitColor = CheckCollisionPointRec(mousePoint, exitButton) ? GRAY : WHITE;
                DrawRectangleRounded(exitButton, 0.3, 6, exitColor);
                DrawText("EXIT", exitButton.x + (exitButton.width - MeasureText("EXIT", 20)) / 2,
                         exitButton.y + (exitButton.height - 20) / 2, 20, BLACK);

                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    if (CheckCollisionPointRec(mousePoint, startButton)) {
                        state = GAMEPLAY;
                    }
                    if (CheckCollisionPointRec(mousePoint, exitButton)) {
                        CloseWindow();
                    }
                }
                EndDrawing();
            }
            else if (state == GAMEPLAY) {
                BeginDrawing();
                ClearBackground(WHITE);
                DrawUI();
                UpdateCats();
                score.DrawScore();
                EndDrawing();
            }
        } catch (const FontNotDetectedException& ex) {
            BeginDrawing();
            ClearBackground(RED);
            std::cout << ex.what();
            EndDrawing();
        } catch (const InvalidKeyException& ex1) {
            BeginDrawing();
            ClearBackground(RED);
            DrawText(ex1.what(), 100, 300, 20, BLACK);
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
        for (int j = i + 1; j < cats.size(); j++) {
            if (abs(cats[i]->getX() - cats[j]->getX()) < (cats[i]->getRadius() + 20) &&
                abs(cats[i]->getY() - cats[j]->getY()) < (cats[i]->getRadius() + 20) &&
                cats[i]->GetIndexCat() == cats[j]->GetIndexCat()) {
                int posX = (cats[i]->getX() + cats[j]->getX()) / 2;
                int posY = (cats[i]->getY() + cats[j]->getY()) / 2;
                if (cats[i]->GetIndexCat() == 1) {
                    cats.erase(cats.begin() + j);
                    cats.erase(cats.begin() + i);
                    cats.push_back(std::make_unique<CatPedro>(posX, posY));
                    score.UpdateScore(100);
                }
                else if (cats[i]->GetIndexCat() == 2) {
                    cats.erase(cats.begin() + j);
                    cats.erase(cats.begin() + i);
                    cats.push_back(std::make_unique<CatPandispan>(posX, posY));
                    score.UpdateScore(100);
                }
                break;
                }
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
//function to spawn a new cat(we pick a random number from 0 to 2 and based on that number spawn a certain cat).
void Game::AddNewCat() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 2);
    switch (dis(gen)) {
        case 0:
            cats.push_back(std::make_unique<CatPedro>(200,10));
        break;
        case 1:
            cats.push_back(std::make_unique<CatPandispan>());
        break;
        case 2:
            cats.push_back(std::make_unique<CatHoratiu>());
        break;
        default:
            cats.push_back(std::make_unique<CatPedro>(200, 10));
        break;
    }
}
//function the game UI, handles boundary also.
void Game::DrawUI() const {
    DrawRectangleRounded({415, 0, 300, 600}, 0, 6, LIGHTGRAY);
    DrawText("Score", 460, 15, 40, BLACK);
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

