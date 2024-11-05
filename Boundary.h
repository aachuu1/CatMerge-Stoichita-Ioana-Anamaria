#pragma once
#include <ostream>

class Boundary {
    int x_margine{};
    int y_margine{};
public:
    Boundary();
    ~Boundary();
    static void Draw();
    void Depasire() const;
    friend std::ostream& operator<<(std::ostream& os, const Boundary& boundary);
};

