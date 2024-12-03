#include "Game.h"

int main() {
    //single instance of the game class
    Game &game = Game::GetInstance();
    game.Run();
    return 0;
}
