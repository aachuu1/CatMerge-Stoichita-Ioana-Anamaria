#pragma once
#include "Cat.h"

// class for a specific type of cat, CatHoratiu
class CatHoratiu : public Cat {
    int radius_horatiu;  // radius specific to CatHoratiu
    int index_horatiu;   // unique index for CatHoratiu

public:
    // constructor with default values for position
    explicit CatHoratiu(int x = 200, int y = 10);

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

    // displays information specific to CatHoratiu
    static void ShowHoratiu();

protected:
    // prints detailed information about the cat
    void PrintInfo() const override;
};
