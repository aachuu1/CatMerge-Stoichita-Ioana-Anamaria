#pragma once
#include <iostream>
#include "Cat.h"
//class derived from base class Cat
class CatPedro : public Cat{
    int radius_pedro;
    int index_pedro;
public:
    CatPedro(int x=200, int y=10) : Cat(x, y), radius_pedro(35), index_pedro(0) {}
    void Draw() override;
    void Update() override;
    [[nodiscard]] std::shared_ptr<Cat> clone() const override {
        return std::make_shared<CatPedro>(*this);
    }
    bool hasReachedGround() const override;
    static void ShowPedro();
    int GetIndexCat() const override;
protected:
    //override function for class Cat that is not a virtual function
    void PrintInfo() const override {
        std::cout << "CatPedro Info: Position(" << x << ", " << y << "), Radius: " << radius_pedro << "\n";
    }
};
