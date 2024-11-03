

#ifndef GAME_H
#define GAME_H
#include <raylib.h>

#include "Boundary.h"
#include "Cat.h"

class Game {
    static Game* instance;
    Font font;
    std::vector<Cat> cats;
    Boundary boundary;
    Game() {
        InitWindow(600, 600, "CatMerge");
        SetTargetFPS(60);
        font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);
        cats.push_back(Cat());
    }
public:
    static Game& GetInstance();
    ~Game();
    void Run();
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;
};



#endif //GAME_H
