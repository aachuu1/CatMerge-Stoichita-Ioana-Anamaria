#include "Game.h"
#include <random>
#include "CatHoratiu.h"
#include "CatPedro.h"
#include "CatPandispan.h"
#include "Exceptions.h"

// observer to handle achievements based on score
class GameAchievementObserver : public IScoreObserver {
private:
    Font& gameFont;
public:
    explicit GameAchievementObserver(Font& font) : gameFont(font) {}

    // triggers achievement when score reaches 3000
    void OnScoreChanged(int newScore) override {
        if (newScore >= 3000) {
            std::cout << "Achievement Unlocked: Master Merger!" << std::endl;
        }
    }
};

// static instance pointer for singleton pattern
Game* Game::instance = nullptr;

// constructor: initializes window, font, cats, and stats
Game::Game() {
    InitWindow(600, 600, "CatMerge");
    SetTargetFPS(80);
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

// destructor: unloads font and closes window
Game::~Game() {
    score.Detach(achievementObserver.get());
    UnloadFont(font);
    CloseWindow();
}

// returns singleton game instance
Game& Game::GetInstance() {
    if (instance == nullptr) {
        instance = new Game();
    }
    return *instance;
}

// main game loop with exception handling
void Game::Run() {
    enum GameState { MENU, GAMEPLAY };
    GameState state = MENU;
    while (!WindowShouldClose()) {
        try {
            CheckForInvalidKeyPress();  // check for invalid key presses
            if (state == MENU) {
                BeginDrawing();
                Texture2D texture = LoadTexture("C:/Users/Ana Stoichita/CLionProjects/CatMerge-Stoichita-Ioana/generated/assets/PhotoStart.png");
                DrawTexture(texture, 0, 0, WHITE);
                DrawText("Cat Merge", 100, 90, 80, BLACK);
                Rectangle startButton = { 200, 200, 170, 45 };
                Rectangle exitButton = { 200, 260, 170, 45 };
                Vector2 mousePoint = GetMousePosition();

                // drawing start and exit buttons with color changes on hover
                Color startColor = CheckCollisionPointRec(mousePoint, startButton) ? GRAY : WHITE;
                DrawRectangleRounded(startButton, 0.3, 6, startColor);
                DrawText("START", startButton.x + (startButton.width - MeasureText("START", 20)) / 2,
                         startButton.y + (startButton.height - 20) / 2, 20, BLACK);

                Color exitColor = CheckCollisionPointRec(mousePoint, exitButton) ? GRAY : WHITE;
                DrawRectangleRounded(exitButton, 0.3, 6, exitColor);
                DrawText("EXIT", exitButton.x + (exitButton.width - MeasureText("EXIT", 20)) / 2,
                         exitButton.y + (exitButton.height - 20) / 2, 20, BLACK);

                // handle button click events
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
            std::cout << ex.what();  // handle missing font exception
            EndDrawing();
        } catch (const InvalidKeyException& ex1) {
            BeginDrawing();
            ClearBackground(RED);
            DrawText(ex1.what(), 100, 300, 20, BLACK);  // handle invalid key exception
            EndDrawing();
        }
    }
}

// checks for invalid key presses
void Game::CheckForInvalidKeyPress() {
    for (int key = 0; key < 350; key++) {
        if (IsKeyDown(key) && key != KEY_LEFT && key != KEY_RIGHT) {
            throw InvalidKeyException();  // throws exception for invalid key
        }
    }
}

// checks if the font is loaded correctly
void Game::CheckFontLoaded() const {
    if(font.texture.id == 0) {
        throw FontNotDetectedException();  // throws exception if font is missing
    }
}

// updates the cats in the game
void Game::UpdateCats() {
    for (int i = 0; i < cats.size(); i++) {
        cats[i]->Draw();
        cats[i]->Update();
        if (cats[i]->hasReachedGround()) {
            if (i == cats.size() - 1) {
                AddNewCat();  // add a new cat when the last one reaches the ground
                score.UpdateScore(200);  // update score
            }
        }
        for (int j = i + 1; j < cats.size(); j++) {
            // check if two cats of same type should merge
            if (abs(cats[i]->getX() - cats[j]->getX()) < (cats[i]->getRadius() + 20) &&
                abs(cats[i]->getY() - cats[j]->getY()) < (cats[i]->getRadius() + 20) &&
                cats[i]->GetIndexCat() == cats[j]->GetIndexCat()) {
                gameStats.IncrementStat("TotalCats");
                int posX = (cats[i]->getX() + cats[j]->getX()) / 2;
                int posY = (cats[i]->getY() + cats[j]->getY()) / 2;
                // handle merging logic based on cat type
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
                    cats.push_back(std::make_unique<CatHoratiu>(posX, posY));
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

// adds a new random cat to the game
void Game::AddNewCat() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 2);
    switch (dis(gen)) {
        case 0:
            cats.push_back(std::make_unique<CatPedro>(200, 10));
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

// draws the UI (score and boundary)
void Game::DrawUI() const {
    DrawRectangleRounded({415, 0, 300, 600}, 0, 6, LIGHTGRAY);
    DrawText("Score", 460, 15, 40, BLACK);
    DrawRectangleRounded({425, 55, 170, 60}, 0.3, 6, PINK);
    Boundary::Draw();
}

// returns the score object
const Score& Game::GetScore() const {
    return score;
}

// returns the boundary object
Boundary Game::GetBoundary() const {
    return boundary;
}

// handles collision and interaction between cats
void Game::CatsTouching(const std::unique_ptr<Cat>& cat1, const std::unique_ptr<Cat>& cat2) {
    for (int i = 0; i < cats.size(); i++) { // iterate through all cats
        for (int j = i + 1; j < cats.size(); j++) { // compare each pair of cats
            double dx = cats[j]->getX() - cats[i]->getX(); // calculate x distance
            double dy = cats[j]->getY() - cats[i]->getY(); // calculate y distance
            bool collisionX = abs(dx) < (cats[i]->getRadius() + cats[j]->getRadius()); // check x collision
            bool collisionY = abs(dy) < (cats[i]->getRadius() + cats[j]->getRadius()); // check y collision

            if (collisionX && collisionY && // if collision detected
                (cats[i]->GetIndexCat() != cats[j]->GetIndexCat() || // cats have different indices
                 cats[j]->GetIndexCat() == 0)) { // or one cat is Pedro, the biggest cat

                // adjust positions to resolve collision
                double overlapX = (cats[i]->getRadius() + cats[j]->getRadius()) - abs(dx); // calculate x overlap
                double overlapY = (cats[i]->getRadius() + cats[j]->getRadius()) - abs(dy); // calculate y overlap

                if (dx > 0) { // resolve x overlap based on direction
                    cats[i]->setX(cats[i]->getX() - overlapX);
                    cats[j]->setX(cats[j]->getX() + overlapX);
                } else {
                    cats[i]->setX(cats[i]->getX() + overlapX);
                    cats[j]->setX(cats[j]->getX() - overlapX);
                }
                if (dy > 0) { // resolve y overlap based on direction
                    cats[i]->setY(cats[i]->getY() - overlapY);
                    cats[j]->setY(cats[j]->getY() + overlapY);
                } else {
                    cats[i]->setY(cats[i]->getY() + overlapY);
                    cats[j]->setY(cats[j]->getY() - overlapY);
                }

                // lambda to adjust positions within screen bounds
                auto adjustToBounds = [](std::unique_ptr<Cat>& cat, int screenWidth, int screenHeight) {
                    if (cat->getX() - cat->getRadius() < 0) { // keep x within left bound
                        cat->setX(cat->getRadius());
                    }
                    if (cat->getX() + cat->getRadius() > screenWidth) { // keep x within right bound
                        cat->setX(screenWidth - cat->getRadius());
                    }
                    if (cat->getY() - cat->getRadius() < 0) { // keep y within top bound
                        cat->setY(cat->getRadius());
                    }
                    if (cat->getY() + cat->getRadius() > screenHeight) { // keep y within bottom bound
                        cat->setY(screenHeight - cat->getRadius());
                    }
                };

                // adjust both cats to fit screen bounds
                adjustToBounds(cats[i], 600, 600);
                adjustToBounds(cats[j], 600, 600);
            }
        }
    }
}

// collisions are not done yet, need to work on the logic.