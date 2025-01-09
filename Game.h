#pragma once
#include <raylib.h>
#include <vector>
#include <memory>
#include "Boundary.h"
#include "Score.h"
#include "Combination.h"
#include "TemplateClass.h"

// forward declaration of GameAchievementObserver class
class GameAchievementObserver;

// singleton game class to manage game state
class Game {
private:
    static Game* instance;  // singleton instance pointer
    Font font{};  // font used for drawing text
    Boundary boundary;  // boundary object that defines game limits
    Score score;  // score object to track game score
    std::vector<std::unique_ptr<Cat>> cats;  // list of unique cat objects
    std::unique_ptr<GameAchievementObserver> achievementObserver;  // observer for achievements
    GameStats<int> gameStats;  // game statistics (e.g., high score, total merges)
    GameStats<int> catStats;  // cat-related statistics (e.g., created, merged)

    Game();  // private constructor for singleton pattern
    ~Game();  // destructor to clean up resources
    static void CheckForInvalidKeyPress();  // checks for invalid key presses
    static void CheckNoKeyPress();  // checks if no keys are pressed
    void CheckFontLoaded() const;  // ensures the font is loaded correctly
    void UpdateCats();  // updates the state of all cats
    void AddNewCat();  // adds a new cat to the game
    void DrawUI() const;  // draws the UI elements such as score and boundaries

public:
    Game(const Game&) = delete;  // prevent copy construction
    Game& operator=(const Game&) = delete;  // prevent copy assignment
    Game(Game&&) = delete;  // prevent move construction
    Game& operator=(Game&&) = delete;  // prevent move assignment

    static Game& GetInstance();  // retrieves the singleton instance of the game
    Combination comb;  // combination object to handle cat merging

    void Run();  // main game loop
    [[nodiscard]] const Score& GetScore() const;  // gets the current score
    [[nodiscard]] Boundary GetBoundary() const;  // gets the game boundary
    void CatsTouching(const std::unique_ptr<Cat>& cat1, const std::unique_ptr<Cat>& cat2);  // handles interactions between cats
};
