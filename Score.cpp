#include "Score.h"
#include "raylib.h"
//constructor
Score::Score(const int score) : score(score), font(LoadFontEx("Font/monogram.ttf", 64, nullptr, 0)) {}
//destructor
Score::~Score() {
    UnloadFont(font);
}
//function for drawing score on screen
void Score::DrawScore() const {
    DrawTextEx(font, TextFormat("%d", score), {500, 70}, 38, 2, BLACK);
}
//setter for score
void Score::SetScore() {
    score=0;
}
//function for updating score
void Score::UpdateScore(int points) {
    score += points;
}