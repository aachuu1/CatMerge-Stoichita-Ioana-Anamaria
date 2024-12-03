#pragma once
#include <iostream>
#include "Cat.h"
//class derived from base class Cat
class CatPedro : public Cat{
    int radius_pedro;
public:
    CatPedro() : Cat(), radius_pedro(35) {}
    void Draw() override;
    void Update() override;
    [[nodiscard]] std::shared_ptr<Cat> clone() const override {
        return std::make_shared<CatPedro>(*this);
    }
    bool hasReachedGround() const override;
    static void ShowPedro();
    protected:
    //override function for class Cat that is not a virtual function
    void PrintInfo() const override {
        std::cout << "CatPedro Info: Position(" << x << ", " << y << "), Radius: " << radius_pedro << "\n";
    }
};
