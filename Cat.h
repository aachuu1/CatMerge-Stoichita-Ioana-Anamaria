#pragma once
#include <memory>

class Cat {
protected:
    float gravity; // gravity affecting the cat
    float speed;   // speed of the cat
    bool isFalling = false; // indicates if the cat is falling
    bool active = true;     // indicates if the cat is active
    int index_cat = 0;      // index of the cat
    virtual void PrintInfo() const = 0; // virtual method to print cat info
    int x, y;       // coordinates of the cat
    int radius;     // radius of the cat

public:
    Cat(int x, int y); // constructor
    virtual ~Cat();    // destructor

    virtual void Draw() = 0;   // pure virtual method to draw the cat
    virtual void Update() = 0; // pure virtual method to update the cat
    virtual int GetIndexCat() const = 0; // pure virtual method to get the cat's index

    [[nodiscard]] virtual std::shared_ptr<Cat> clone() const = 0; // pure virtual clone method
    [[nodiscard]] virtual bool hasReachedGround() const = 0; // pure virtual method to check if the cat reached the ground

    [[nodiscard]] int getX() const; // getter for x-coordinate
    [[nodiscard]] int getY() const; // getter for y-coordinate
    [[nodiscard]] int getRadius() const; // getter for radius

    void setX(int newX); // setter for x-coordinate
    void setY(int newY); // setter for y-coordinate

    void ShowInfo() const { PrintInfo(); } // calls the PrintInfo method
};
