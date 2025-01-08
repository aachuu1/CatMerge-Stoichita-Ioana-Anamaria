#include "Game.h"
#include <random>
#include "CatHoratiu.h"
#include "CatPedro.h"
#include "CatPandispan.h"
#include "Exceptions.h"

class GameAchievementObserver : public IScoreObserver {
private:
    Font& gameFont;
public:
    explicit GameAchievementObserver(Font& font) : gameFont(font) {}

    void OnScoreChanged(int newScore) override {
        if (newScore >= 3000) {
            std::cout << "Achievement Unlocked: Master Merger!" << std::endl;
        }
    }
};

//static instance pointer
Game* Game::instance = nullptr;

//constructor to initialize game window, cats and font
Game::Game() {
    InitWindow(600, 600, "CatMerge");
    SetTargetFPS(60);
    font = LoadFontEx("Font/monogram.ttf", 64, nullptr, 0);
    CheckFontLoaded();
    cats.push_back(std::make_unique<CatPedro>(200, 10));
    achievementObserver = std::make_unique<GameAchievementObserver>(font);
    score.Attach(achievementObserver.get());
    gameStats.UpdateStat("TotalCats", 0);
    gameStats.UpdateStat("TotalMerges", 0);
    gameStats.UpdateStat("HighScore", 0);
    catStats.UpdateStat("PedroCreated", 0);
    catStats.UpdateStat("HoratiuCreated", 0);
    catStats.IncrementStat("PedroCreated");
    catStats.UpdateStat("PandispanCreated", 0);
    catStats.UpdateStat("HoratiuCreated", 0);
}

//destructor to unload the font and close the window
Game::~Game() {
    score.Detach(achievementObserver.get());
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
                Texture2D texture = LoadTexture("C:/Users/Ana Stoichita/CLionProjects/CatMerge-Stoichita-Ioana/generated/assets/PhotoStart.png");
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
                        score.SetScore();
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


void Game::CheckForInvalidKeyPress() {
    for (int key = 0; key < 350; key++) {
        if (IsKeyDown(key) && key != KEY_LEFT && key != KEY_RIGHT) {
            throw InvalidKeyException();
        }
    }
}

void Game::CheckFontLoaded() const {
    if(font.texture.id==0) {
        throw FontNotDetectedException();
    }
}

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
                gameStats.IncrementStat("TotalCats");
                int posX = (cats[i]->getX() + cats[j]->getX()) / 2;
                int posY = (cats[i]->getY() + cats[j]->getY()) / 2;
                if (cats[i]->GetIndexCat() == 1) {
                    cats.erase(cats.begin() + j);
                    cats.erase(cats.begin() + i);
                    cats.push_back(std::make_unique<CatPedro>(posX, posY));
                    score.UpdateScore(100);
                    if (score.GetScore() > gameStats.GetStat("HighScore")) {
                        gameStats.UpdateStat("HighScore", score.GetScore());
                    }
                }
                else if (cats[i]->GetIndexCat() == 2) {
                    cats.erase(cats.begin() + j);
                    cats.erase(cats.begin() + i);
                    cats.push_back(std::make_unique<CatPandispan>(posX, posY));
                    score.UpdateScore(100);
                    if (score.GetScore() > gameStats.GetStat("HighScore")) {
                        gameStats.UpdateStat("HighScore", score.GetScore());
                    }
                }
                break;
            }
            CatsTouching(cats[i], cats[j]);
        }
    }
}

void Game::AddNewCat() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 2);
    switch (dis(gen)) {
        case 0:
            cats.push_back(std::make_unique<CatPedro>(200,10));
            gameStats.IncrementStat("TotalCats");
            break;
        case 1:
            cats.push_back(std::make_unique<CatPandispan>());
            gameStats.IncrementStat("TotalCats");
            break;
        case 2:
            cats.push_back(std::make_unique<CatHoratiu>());
            gameStats.IncrementStat("TotalCats");
            break;
        default:
            cats.push_back(std::make_unique<CatPedro>(200, 10));
            gameStats.IncrementStat("TotalCats");
            break;
    }
}

void Game::DrawUI() const {
    DrawRectangleRounded({415, 0, 300, 600}, 0, 6, LIGHTGRAY);
    DrawText("Score", 460, 15, 40, BLACK);
    DrawRectangleRounded({425, 55, 170, 60}, 0.3, 6, PINK);
    Boundary::Draw();
}

const Score& Game::GetScore() const {
    return score;
}

Boundary Game::GetBoundary() const {
    return boundary;
}

void Game::CatsTouching(const std::unique_ptr<Cat>& cat1, const std::unique_ptr<Cat>& cat2) {
    for (int i = 0; i < cats.size(); i++) {
        for (int j = i+1; j < cats.size(); j++) {
            double dx = cats[j]->getX() - cats[i]->getX();
            double dy = cats[j]->getY() - cats[i]->getY();
            bool collisionX = abs(dx) < (cats[i]->getRadius() + cats[j]->getRadius());
            bool collisionY = abs(dy) < (cats[i]->getRadius() + cats[j]->getRadius());
            if (collisionX && collisionY && cats[i]->GetIndexCat() != cats[j]->GetIndexCat()) {
                double overlapX = (cats[i]->getRadius() + cats[j]->getRadius()) - abs(dx);
                double overlapY = (cats[i]->getRadius() + cats[j]->getRadius()) - abs(dy);
                if (dx > 0) {
                    cats[i]->x -= overlapX;
                    cats[j]->x += overlapX;
                } else {
                    cats[i]->x += overlapX;
                    cats[j]->x -= overlapX;
                }
                if (cats[j]->y > cats[i]->y) {
                    cats[j]->y += overlapY ;
                    cats[i]->y -= overlapY ;
                } else {
                    cats[j]->y -= overlapY ;
                    cats[i]->y += overlapY ;
                }
                if (cats[i]->getY() < 0) {
                    cats[i]->y = cats[i]->getRadius();
                }

                if (cats[j]->getY() < 0) {
                    cats[j]->y = cats[j]->getRadius();
                }
            }
        }
    }
}