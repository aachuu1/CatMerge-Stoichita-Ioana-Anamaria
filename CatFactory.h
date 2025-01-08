#pragma once
#include <memory>

class CatFactory {
public:
    virtual ~CatFactory();
    [[nodiscard]] virtual std::shared_ptr<CatFactory> createCat(int x , int y) = 0;
};
