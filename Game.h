#pragma once
#include <raylib.h>
#include "Boundary.h"
#include "Cat.h"

class Game{
    static Game* instance;
    Font font{};
    Cat cats;
    Boundary boundary;
    Game(){
        InitWindow(600, 600, "CatMerge");
        SetTargetFPS(60);
        font = LoadFontEx("Font/monogram.ttf", 64, nullptr, 0);
    }
public:
    static Game& GetInstance();
    ~Game();
    void Run();
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;
};

