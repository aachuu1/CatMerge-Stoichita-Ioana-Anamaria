#pragma once
#include "Cat.h"

class CatHoratiu : public Cat {
    int radius_horatiu;
    int index_horatiu;

public:
    explicit CatHoratiu(int x = 200, int y = 10);
    void Draw() override;
    void Update() override;
    [[nodiscard]] std::shared_ptr<Cat> clone() const override;
    bool hasReachedGround() const override;
    int GetIndexCat() const override;
    static void ShowHoratiu();

protected:
    void PrintInfo() const override;
};
