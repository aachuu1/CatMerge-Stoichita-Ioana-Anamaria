#pragma once
#include "Cat.h"

class CatPedro : public Cat {
    int radius_pedro;
    int index_pedro;

public:
    explicit CatPedro(int x = 200, int y = 10);
    void Draw() override;
    void Update() override;
    [[nodiscard]] std::shared_ptr<Cat> clone() const override;
    bool hasReachedGround() const override;
    int GetIndexCat() const override;
    static void ShowPedro();

protected:
    void PrintInfo() const override;
};
