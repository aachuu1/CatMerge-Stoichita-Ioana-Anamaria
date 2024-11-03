#include <stdio.h>
#include "Cat.h"
#include <vector>
#include <raylib.h>
#include "Boundary.h"
#include "Game.h"

//clasa singleton pentru joc pe care sa o apelez o singura data

int main() {
    Game::GetInstance().Run();
    return 0;
}
