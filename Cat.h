#pragma once

class Cat{
    int x,y;
    float gravity;
    float speed;
    int radius;
    bool isFalling=false;
    bool active=true;
public:
    Cat();
    ~Cat();
    void Draw() const;
    void Update();
    [[nodiscard]] int getX() const;
    [[nodiscard]] int getY() const;
    void setX(int newX);
    void setY(int newY);
    [[nodiscard]] bool hasReachedGround() const;
};


