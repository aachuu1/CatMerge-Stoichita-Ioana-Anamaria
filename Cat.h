#pragma once
#include <memory>
//base class for cats
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
    [[nodiscard]] virtual std::shared_ptr<Cat> clone() const = 0;
    [[nodiscard]] int getX() const;
    [[nodiscard]] int getY() const;
    [[nodiscard]] int getRadius() const;
    void setX(int newX);
    void setY(int newY);
    [[nodiscard]] virtual bool hasReachedGround() const =0;
    void ShowInfo() const { PrintInfo(); }
};


