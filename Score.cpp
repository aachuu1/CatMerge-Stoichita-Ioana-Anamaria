#include "Score.h"
#include <algorithm>

Score::Score(const int score) : score(score), font(LoadFontEx("Font/monogram.ttf", 64, nullptr, 0)) {

}

Score::~Score() {
    UnloadFont(font);
}

void Score::Attach(IScoreObserver* observer) {
    observers.push_back(observer);
}

void Score::Detach(IScoreObserver* observer) {
    observers.erase(
        std::remove(observers.begin(), observers.end(), observer),
        observers.end()
    );
}

void Score::Notify() {
    for (auto observer : observers) {
        observer->OnScoreChanged(score);
    }
}

void Score::DrawScore() const {
    DrawTextEx(font, TextFormat("%d", score), {500, 70}, 38, 2, BLACK);
}

void Score::SetScore() {
    score = 0;
    Notify();
}

void Score::UpdateScore(int points) {
    score += points;
    Notify();
}


class AchievementObserver : public IScoreObserver {
public:
    void OnScoreChanged(int newScore) override {
        if (newScore >= 1000) {
            DrawTextEx(GetFontDefault(),
                      "Achievement Unlocked!",
                      Vector2{200, 200},
                      38,
                      2,
                      BLACK);
        }
    }
};

class HighScoreObserver : public IScoreObserver {
private:
    int highScore = 0;

public:
    void OnScoreChanged(int newScore) override {
        if (newScore > highScore) {
            highScore = newScore;
        }
    }
};

int Score::GetScore() const {
    return score;
}