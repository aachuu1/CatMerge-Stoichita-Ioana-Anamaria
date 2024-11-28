#include <iostream>
#include "Game.h"

int main() {
    Game &game = Game::GetInstance();
    Cat cat1;
    Cat cat2;
    cat2=cat1;
    Boundary boundary;
    Score score;
    game.Run();
    return 0;
}
