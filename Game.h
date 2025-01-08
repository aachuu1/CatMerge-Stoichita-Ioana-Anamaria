#pragma once
#include <raylib.h>
#include <vector>
#include <memory>
#include "Boundary.h"
#include "Score.h"
#include "Combination.h"
#include "TemplateClass.h"

class GameAchievementObserver;

//singleton class for game
class Game {
private:
    static Game* instance;
    Font font{};
    Boundary boundary;
    Score score;
    std::vector<std::unique_ptr<Cat>> cats;
    std::unique_ptr<GameAchievementObserver> achievementObserver;
    GameStats<int> gameStats;
    GameStats<int> catStats;
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
    Combination comb;
    void Run();
    [[nodiscard]] const Score& GetScore() const;
    [[nodiscard]] Boundary GetBoundary() const;
    void CatsTouching(const std::unique_ptr<Cat>& cat1, const std::unique_ptr<Cat>& cat2);
};