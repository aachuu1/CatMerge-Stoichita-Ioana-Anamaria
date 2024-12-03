#pragma once
#include "Cat.h"
class Combination {
private:
    bool CatsTouching=false;
    public:
    Combination();
    ~Combination();
    static bool touching(const Cat *c1, const Cat *c2);
};

