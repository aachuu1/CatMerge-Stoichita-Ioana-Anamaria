#pragma once
#include <iostream>
#include "Cat.h"
//class derived from base class Cat
class CatHoratiu : public Cat{
    int radius_horatiu;
public:
    CatHoratiu() : Cat(), radius_horatiu(20) {}
    void Draw() override;
    void Update() override;
    [[nodiscard]] std::shared_ptr<Cat> clone() const override {
        return std::make_shared<CatHoratiu>(*this);
    }
    bool hasReachedGround() const override;
    static void ShowHoratiu();
protected:
    //override function for class Cat that is not a virtual function
    void PrintInfo() const override {
        std::cout << "CatPedro Info: Position(" << x << ", " << y << "), Radius: " << radius_horatiu<< "\n";
    }
};
