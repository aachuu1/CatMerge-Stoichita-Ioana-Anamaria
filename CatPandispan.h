#pragma once
#include <iostream>

#include "Cat.h"

class CatPandispan : public Cat{
    int radius_pandispan;
public:
    CatPandispan() : Cat(), radius_pandispan(40) {}
    void Draw() override;
    void Update() override;
    std::shared_ptr<Cat> clone() const override {
        return std::make_shared<CatPandispan>(*this);
    }
protected:
    void PrintInfo() const override {
        std::cout << "CatPedro Info: Position(" << x << ", " << y << "), Radius: " << radius_pandispan<< "\n";
    }
};
