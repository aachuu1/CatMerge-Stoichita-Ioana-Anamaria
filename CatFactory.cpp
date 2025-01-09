#include "CatFactory.h"
#include "CatHoratiu.h"
#include "CatPandispan.h"
#include "CatPedro.h"
#include "Cat.h"
// factory for creating PedroCat objects
class PedroCatFactory : public CatFactory {
public:
    // creates a CatPedro object with the specified coordinates
    [[nodiscard]] std::shared_ptr<Cat> CreateCat(int x, int y) const {
        return std::make_shared<CatPedro>(x, y);
    }
};

// factory for creating PandispanCat objects
class PandispanCatFactory : public CatFactory {
public:
    // creates a CatPandispan object with the specified coordinates
    [[nodiscard]] std::shared_ptr<Cat> CreateCat(int x, int y) const  {
        return std::make_shared<CatPandispan>(x, y);
    }
};

// factory for creating HoratiuCat objects
class HoratiuCatFactory : public CatFactory {
public:
    // creates a CatHoratiu object with the specified coordinates
    [[nodiscard]] std::shared_ptr<Cat> CreateCat(int x, int y) const {
        return std::make_shared<CatHoratiu>(x, y);
    }
};
