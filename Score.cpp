#include "Score.h"
#include "raylib.h"

Score::Score(const int score) : score(score), font(LoadFontEx("Font/monogram.ttf", 64, nullptr, 0)) {}

Score::~Score() {
    UnloadFont(font);
}

void Score::DrawScore() const {
    DrawTextEx(font, TextFormat("%d", score), {500, 70}, 38, 2, BLACK);
}
void Score::UpdateScore(int points) {
    score = 0;
    score += points;
}