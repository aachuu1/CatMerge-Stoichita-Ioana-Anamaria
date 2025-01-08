#include "CatFactory.h"
#include "CatHoratiu.h"
#include "CatPandispan.h"
#include "CatPedro.h"

CatFactory::~CatFactory() {

}
class PedroCatFactory : public CatFactory {
public:
    [[nodiscard]] std::shared_ptr<Cat> CreateCat(int x, int y) const {
        return std::make_shared<CatPedro>(x, y);
    }
};

class PandispanCatFactory : public CatFactory {
public:
    [[nodiscard]] std::shared_ptr<Cat> CreateCat(int x, int y) const {
        return std::make_shared<CatPandispan>(x, y);
    }
};
class HoratiuCatFactory : public CatFactory {
public:
    [[nodiscard]] std::shared_ptr<Cat> CreateCat(int x, int y) const {
        return std::make_shared<CatHoratiu>(x, y);
    }
};
