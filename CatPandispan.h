#pragma once
#include "Cat.h"

// class for a specific type of cat, CatPandispan
class CatPandispan : public Cat {
    int radius_pandispan;  // radius specific to CatPandispan
    int index_pandispan;   // unique index for CatPandispan

public:
    // constructor with default position values
    explicit CatPandispan(int x = 200, int y = 10);

    // overrides the base class draw method
    void Draw() override;

    // overrides the base class update method
    void Update() override;

    // clones the current object
    [[nodiscard]] std::shared_ptr<Cat> clone() const override;

    // checks if the cat has reached the ground
    bool hasReachedGround() const override;

    // returns the unique index for this cat
    int GetIndexCat() const override;

    // displays information specific to CatPandispan
    static void ShowPandispan();

protected:
    // prints detailed information about the cat
    void PrintInfo() const override;
};
