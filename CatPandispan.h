#pragma once
#include <iostream>
#include "Cat.h"
//class derived from base class Cat
class CatPandispan : public Cat{
    int radius_pandispan;
public:
    CatPandispan() : Cat(), radius_pandispan(30) {}
    void Draw() override;
    void Update() override;
    [[nodiscard]] std::shared_ptr<Cat> clone() const override {
        return std::make_shared<CatPandispan>(*this);
    }
    static void ShowPandispan();
    bool hasReachedGround() const override;
protected:
    //override function for class Cat that is not a virtual function
    void PrintInfo() const override {
        std::cout << "CatPedro Info: Position(" << x << ", " << y << "), Radius: " << radius_pandispan<< "\n";
    }
};
