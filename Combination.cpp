#include "Combination.h"
#include "Cat.h"
Combination::Combination() {

}
Combination::~Combination() {

}
bool Combination::touching(Cat *c1, Cat *c2) {
     return c1->getY()==c2->getY() && c1->getX()==c2->getX();
}
