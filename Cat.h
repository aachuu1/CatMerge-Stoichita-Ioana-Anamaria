#pragma once

class Cat{
    float x,y, gravity;
    float speed;
    float radius;
    bool isFalling=false;

public:
    Cat();
    Cat(const Cat& other) : x(200), y(10), gravity(3), speed(5), radius(30), isFalling(other.isFalling) {};
    ~Cat();
    void Draw() const;
    void Update();
    [[nodiscard]] int getX() const;
    [[nodiscard]] int getY() const;
    void setX(int newX);
    void setY(int newY);
    [[nodiscard]] bool hasReachedGround() const;
};


