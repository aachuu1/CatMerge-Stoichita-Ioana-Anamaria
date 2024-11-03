#include "Boundary.h"
#include "Cat.h"
#include <raylib.h>
Boundary::Boundary() {

}
Boundary::~Boundary() {

}
void Boundary::Draw() {
    DrawRectangle(0, 100, 415, 3, BLACK);
}
void Boundary::Depasire() {
    Cat pisica;
    if(pisica.getX()>x_margine&&pisica.getY()>y_margine) {
        DrawText("Pisica a depasit linia!", 10, 10, 20, RED);
    }
}
