#pragma once
#include <iostream>

#include "Cat.h"

class CatPedro : public Cat{
    int radius_pedro;
public:
    CatPedro() : Cat(), radius_pedro(50) {}
    void Draw() override;
    void Update() override;
    [[nodiscard]] std::shared_ptr<Cat> clone() const override {
        return std::make_shared<CatPedro>(*this);
    }
    bool hasReachedGround() const override;
    static void ShowPedro();
    protected:
    void PrintInfo() const override {
        std::cout << "CatPedro Info: Position(" << x << ", " << y << "), Radius: " << radius_pedro << "\n";
    }
};
