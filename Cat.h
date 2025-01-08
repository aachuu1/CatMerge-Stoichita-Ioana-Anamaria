#pragma once
#include <memory>
#include <iostream>

// Base class for cats (Abstract Factory)
class Cat {
protected:
    float gravity;
    float speed;
    bool isFalling = false;
    bool active = true;
    int index_cat = 0;
    virtual void PrintInfo() const = 0;
public:
    int x, y;
    int radius;
    Cat(int x, int y);
    virtual ~Cat();
    virtual void Draw() = 0;
    virtual void Update() = 0;
    virtual int GetIndexCat() const = 0;
    [[nodiscard]] virtual std::shared_ptr<Cat> clone() const = 0;
    [[nodiscard]] virtual bool hasReachedGround() const = 0;
    [[nodiscard]] int getX() const;
    [[nodiscard]] int getY() const;
    [[nodiscard]] int getRadius() const;
    void setX(int newX);
    void setY(int newY);
    void ShowInfo() const { PrintInfo(); }
};
