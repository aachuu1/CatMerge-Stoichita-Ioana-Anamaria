#pragma once
#include "Cat.h"

// Concrete Factory: Derived class from Cat
class CatPedro : public Cat {
    int radius_pedro;
    int index_pedro;

public:
    // Constructor with default parameters
    CatPedro(int x = 200, int y = 10);

    // Overridden methods from base class
    void Draw() override;
    void Update() override;
    [[nodiscard]] std::shared_ptr<Cat> clone() const override;
    bool hasReachedGround() const override;
    int GetIndexCat() const override;

    // Static method specific to CatPedro
    static void ShowPedro();

protected:
    // Override for cat-specific info
    void PrintInfo() const override;
};
