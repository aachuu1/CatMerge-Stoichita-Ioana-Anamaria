#pragma once
#include "Cat.h"
#include <raylib.h>
#include "Boundary.h"
#include "Score.h"
#include <ostream>
#include <vector>
class Game{
    static Game* instance;
    Font font{};
    Boundary boundary;
    Score score;
    std::vector<Cat> cats;
    int lastSpawnTime;
    Game();
    ~Game();

public:
    static Game& GetInstance();
    void Run();
    Game(const Game&) = delete;
    Game(const Game&&) = delete;
    Game& operator=(const Game&&) = delete;
    Game& operator=(const Game&) = delete;
    [[nodiscard]] Score GetScore() const;
    [[nodiscard]] Cat GetCat() const;
    [[nodiscard]] Boundary GetBoundary() const;
};
