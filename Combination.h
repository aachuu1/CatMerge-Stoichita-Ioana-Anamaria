#pragma once
#include "Cat.h"
//class for cat combinations
class Combination {
private:
    bool CatsTouching=false;
    public:
    Combination();
    ~Combination();
    //bool function to determine if the cats are touching (not the right implementation!!)
    static bool touching(const Cat *c1, const Cat *c2);
};

