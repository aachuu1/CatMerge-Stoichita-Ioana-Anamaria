#pragma once
#include "Cat.h"
#include <raylib.h>
#include "Boundary.h"
#include "Score.h"

class Game{
    static Game* instance;
    Font font{};
    Boundary boundary;
    Score score;
    Cat originalCat;
    Cat constructorCopiedCat;
    Cat operatorCopiedCat;
    Game();
    ~Game();

public:
    static Game& GetInstance();
    void Run();
    Game(const Game&) = delete;
    Game(const Game&&) = delete;
    Game& operator=(const Game&&) = delete;
    Game& operator=(const Game&) = delete;

    Score GetScore();
};
