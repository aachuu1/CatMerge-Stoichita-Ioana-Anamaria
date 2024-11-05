#pragma once
#include "raylib.h"
#include <ostream>

class Score {
    int score;
    Font font{};
    public:
    Score();
    ~Score();
    void UpdateScore(int points);
    void DrawScore();
    friend std::ostream& operator<<(std::ostream& os, const Score& score);
};
