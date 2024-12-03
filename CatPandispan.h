#pragma once
#include <iostream>

#include "Cat.h"

class CatPandispan : public Cat{
    int radius_pandispan;
public:
    CatPandispan() : Cat(), radius_pandispan(60) {}
    void Draw() override;
    void Update() override;
    [[nodiscard]] std::shared_ptr<Cat> clone() const override {
        return std::make_shared<CatPandispan>(*this);
    }
    static void ShowPandispan();
    bool hasReachedGround() const override;
protected:
    void PrintInfo() const override {
        std::cout << "CatPedro Info: Position(" << x << ", " << y << "), Radius: " << radius_pandispan<< "\n";
    }
};
