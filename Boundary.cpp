#include "Boundary.h"
#include <iostream>
#include <ostream>
#include <raylib.h>

Boundary::Boundary() = default;

Boundary::~Boundary(){
    std::cout << "Boundary-ul a fost distrus" << std::endl;
}

void Boundary::Draw() {
    DrawRectangle(0, 100, 415, 3, BLACK);
}


