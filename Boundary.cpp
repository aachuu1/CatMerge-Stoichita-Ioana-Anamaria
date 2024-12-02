#include "Boundary.h"
#include <iostream>
#include <ostream>
#include "Cat.h"
#include <raylib.h>

Boundary::Boundary() = default;

Boundary::~Boundary(){
    std::cout << "Boundary-ul a fost distrus" << std::endl;
}

void Boundary::Draw() {
    DrawRectangle(0, 100, 415, 3, BLACK);
}

// void Boundary::Depasire() const {
//     Cat pisica;
//     if(pisica.getX()>x_margine&&pisica.getY()>y_margine) {
//         DrawText("Pisica a depasit linia!", 10, 10, 20, RED);
//     }
// }

