#include "Combination.h"
#include "Cat.h"
//constructor
Combination::Combination() = default;
//destructor
Combination::~Combination() = default;
bool Combination::touching(const Cat *c1, const Cat *c2) {
     return c1->getY()==c2->getY() && c1->getX()==c2->getX();
}
