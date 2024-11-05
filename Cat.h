#pragma once
#include <ostream>

class Cat{
    int x,y;
    float gravity;
    float speed;
    int radius;
    bool isFalling=false;

public:
    Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    ~Cat();
    void Draw() const;
    void Update();
    [[nodiscard]] int getX() const;
    [[nodiscard]] int getY() const;
    void setX(int newX);
    void setY(int newY);
    [[nodiscard]] bool hasReachedGround() const;
    friend std::ostream& operator<<(std::ostream& os, const Cat& cat);
};


