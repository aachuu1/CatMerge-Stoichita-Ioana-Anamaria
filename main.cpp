#include <iostream>
#include "Game.h"

int main() {
    Game &game = Game::GetInstance();
    Boundary boundary;
    Score score;
    game.Run();
    return 0;
}
