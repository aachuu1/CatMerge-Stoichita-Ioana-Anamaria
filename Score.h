#pragma once
#include "raylib.h"
#include <ostream>

class Score {
    int score;
    Font font{};
    public:
    explicit Score(int score=0);
    ~Score();
    void UpdateScore(int points);
    void DrawScore();
    friend std::ostream& operator<<(std::ostream& os, const Score& score);
};
