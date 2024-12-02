#pragma once
#include "Cat.h"

class CatHoratiu : public Cat{
    int radius_horatiu;
    int index_horatiu;
public:
    CatHoratiu() : Cat(), radius_horatiu(80), index_horatiu(2) {}
    void Draw() override;
    void Update() override;
};
