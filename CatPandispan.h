#pragma once
#include "Cat.h"

class CatPandispan : public Cat{
    int radius_pandispan;
    int index_pandispan;
public:
    CatPandispan() : Cat(), radius_pandispan(60), index_pandispan(4) {}
    void Draw() override;
    void Update() override;
};
