#pragma once
#include <iostream>
#include "Cat.h"
//class derived from base class Cat
class CatHoratiu : public Cat{
    int radius_horatiu;
    int index_horatiu;
public:
    CatHoratiu(int x=200, int y=10) : Cat(x, y), radius_horatiu(20), index_horatiu(2) {}
    void Draw() override;
    void Update() override;
    [[nodiscard]] std::shared_ptr<Cat> clone() const override {
        return std::make_shared<CatHoratiu>(*this);
    }
    bool hasReachedGround() const override;
    static void ShowHoratiu();
    int GetIndexCat() const override;
protected:
    //override function for class Cat that is not a virtual function
    void PrintInfo() const override {
        std::cout << "CatPedro Info: Position(" << x << ", " << y << "), Radius: " << radius_horatiu<< "\n";
    }
};
