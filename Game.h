#include "Cat.h"
#include <raylib.h>

class Game {
    static Game* instance;
    Font font{};
    Cat originalCat;
    Cat copiedCat;
    Game();

public:
    static Game& GetInstance();
    ~Game();
    void Run();
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;
};
