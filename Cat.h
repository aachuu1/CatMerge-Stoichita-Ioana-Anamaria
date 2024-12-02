#pragma once
#include <exception>
#include <stdexcept>
#include <string>

#include "raylib.h"

class Cat{
protected:
    float gravity;
    float speed;
    bool isFalling=false;
    bool active=true;
    int index;
public:
    int x,y;
    int radius;
    Cat();
    virtual ~Cat();
    virtual void Draw();
    virtual void Update();
    [[nodiscard]] int getX() const;
    [[nodiscard]] int getY() const;
    [[nodiscard]] int getRadius() const;
    void setX(int newX);
    void setY(int newY);
    [[nodiscard]] bool hasReachedGround() const;

};


