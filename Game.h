#pragma once
#include <raylib.h>
#include <vector>
#include <memory>
#include "Boundary.h"
#include "Score.h"
#include "CatPedro.h"
class Game {
private:
    static Game* instance;
    Font font{};
    Boundary boundary;
    Score score;
    std::vector<std::unique_ptr<Cat>> cats;
    int lastSpawnTime{};
    Game();
    ~Game();

    static void CheckForInvalidKeyPress();
    static void CheckNoKeyPress();
    void CheckFontLoaded() const;
    void UpdateCats();
    void AddNewCat();
    void DrawUI() const;

public:
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;
    Game(Game&&) = delete;
    Game& operator=(Game&&) = delete;
    static Game& GetInstance();
    void Run();
    [[nodiscard]] Score GetScore() const;
    [[nodiscard]] Boundary GetBoundary() const;
};
