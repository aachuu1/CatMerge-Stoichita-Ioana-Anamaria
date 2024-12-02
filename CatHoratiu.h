#pragma once
#include <iostream>

#include "Cat.h"

class CatHoratiu : public Cat{
    int radius_horatiu;
public:
    CatHoratiu() : Cat(), radius_horatiu(40) {}
    void Draw() override;
    void Update() override;
    std::shared_ptr<Cat> clone() const override {
        return std::make_shared<CatHoratiu>(*this);
    }
protected:
    void PrintInfo() const override {
        std::cout << "CatPedro Info: Position(" << x << ", " << y << "), Radius: " << radius_horatiu<< "\n";
    }
};
