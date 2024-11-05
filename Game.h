#pragma once
#include "Cat.h"
#include <raylib.h>
#include "Boundary.h"
#include "Score.h"
#include <ostream>
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
    [[nodiscard]] Score GetScore() const;
    [[nodiscard]] Cat GetCat() const;
    [[nodiscard]] Boundary GetBoundary() const;

    [[nodiscard]] float GetOriginalCatX() const { return originalCat.getX(); }
    [[nodiscard]] float GetConstructorCopiedCatX() const { return constructorCopiedCat.getX(); }
    [[nodiscard]] float GetOperatorCopiedCatX() const { return operatorCopiedCat.getX(); }
    friend std::ostream& operator<<(std::ostream& os, const Game& game);
};
