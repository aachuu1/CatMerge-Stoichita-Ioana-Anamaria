#pragma once
#include "raylib.h"

class Score {
    int score;
    Font font{};
    public:
    explicit Score(int score=0);
    ~Score();
    void UpdateScore(int points);
    void DrawScore() const;
    [[nodiscard]] int getScore() const {
        return score;
    };
};
