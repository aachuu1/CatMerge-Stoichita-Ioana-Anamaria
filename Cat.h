#pragma once
#include <vector>

class Cat{
    float x,y, gravity;
    float speed;
    float radius;
    bool isFalling=false;
    std::vector<Cat> pisici;

public:
    Cat();
    ~Cat();
    void Draw() const;
    void Update();
    [[nodiscard]] int getX() const;
    [[nodiscard]] int getY() const;
    [[nodiscard]] bool hasReachedGround() const;
};


