#include "Boundary.h"
#include <iostream>
#include <ostream>
#include <raylib.h>
//constructor for boundary, set to default
Boundary::Boundary() = default;
//destructor for boundary
Boundary::~Boundary(){
    std::cout << "Boundary-ul a fost distrus" << std::endl;
}
//function that draws the boundary on screen
void Boundary::Draw() {
    DrawRectangle(0, 100, 415, 3, BLACK);
}

//not yet done, need to implement function for boundary so that the cats don't cross it.