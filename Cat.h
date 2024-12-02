#pragma once
#include <memory>

class Cat{
protected:
    float gravity;
    float speed;
    bool isFalling=false;
    bool active=true;
    int index;
    virtual void PrintInfo() const = 0;
public:
    int x,y;
    int radius;
    Cat();
    virtual ~Cat();
    virtual void Draw() = 0;
    virtual void Update() = 0;
    virtual std::shared_ptr<Cat> clone() const = 0;
    [[nodiscard]] int getX() const;
    [[nodiscard]] int getY() const;
    [[nodiscard]] int getRadius() const;
    void setX(int newX);
    void setY(int newY);
    [[nodiscard]] bool hasReachedGround() const;
    void ShowInfo() const { PrintInfo(); }
};


