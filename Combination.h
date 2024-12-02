#pragma once
#include "Cat.h"
class Combination {
private:
    bool CatsTouching=false;
    public:
    Combination();
    ~Combination();
    bool touching(Cat *c1, Cat *c2);
};

