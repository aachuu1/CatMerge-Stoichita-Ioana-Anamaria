#include <iostream>
#include "Score.h"
#include "Game.h"

int main() {
    Game &game = Game::GetInstance();
    game.Run();
    Cat cat1;
    Cat cat2;
    cat2=cat1;
    std::cout << game.GetScore() << std::endl;
    std::cout << game.GetCat() << std::endl;
    std::cout << game.GetBoundary() << std::endl;
    return 0;
}
