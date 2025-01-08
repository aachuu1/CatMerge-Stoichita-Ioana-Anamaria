#pragma once
#include "Cat.h"

// Concrete Factory: Derived class from Cat
class CatPandispan : public Cat {
    int radius_pandispan;
    int index_pandispan;

public:
    // Constructor with default parameters
    CatPandispan(int x = 200, int y = 10);
    // Overridden methods from base class
    void Draw() override;
    void Update() override;
    [[nodiscard]] std::shared_ptr<Cat> clone() const override;
    bool hasReachedGround() const override;
    int GetIndexCat() const override;

    // Static method specific to CatPedro
    static void ShowPandispan();

protected:
    // Override for cat-specific info
    void PrintInfo() const override;
};
