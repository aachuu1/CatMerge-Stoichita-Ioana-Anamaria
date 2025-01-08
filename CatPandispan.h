#pragma once
#include "Cat.h"

class CatPandispan : public Cat {
    int radius_pandispan;
    int index_pandispan;

public:
    explicit CatPandispan(int x = 200, int y = 10);
    void Draw() override;
    void Update() override;
    [[nodiscard]] std::shared_ptr<Cat> clone() const override;
    bool hasReachedGround() const override;
    int GetIndexCat() const override;
    static void ShowPandispan();

protected:
    void PrintInfo() const override;
};
