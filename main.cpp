#include <iostream>
#include "Score.h"
#include "Game.h"

int main() {
    Game &game = Game::GetInstance();
    game.Run();
    std::cout << game.GetScore() << std::endl;
    return 0;
}
