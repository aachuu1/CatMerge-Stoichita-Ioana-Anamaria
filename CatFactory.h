#pragma once
#include <memory>
#include "Cat.h"
class CatFactory {
public:
    // pure virtual method to create a Cat object with specified coordinates
    [[nodiscard]] virtual std::shared_ptr<Cat> CreateCat(int x, int y) = 0;
    virtual ~CatFactory() = default; // virtual destructor for cleanup
};
