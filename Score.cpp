#include "Score.h"
#include <algorithm>

// constructor to initialize score and font
Score::Score(const int score) : score(score), font(LoadFontEx("Font/monogram.ttf", 64, nullptr, 0)) {}

// destructor to unload font when object is destroyed
Score::~Score() {
    UnloadFont(font);
}

// attach an observer to monitor score changes
void Score::Attach(IScoreObserver* observer) {
    observers.push_back(observer);
}

// detach an observer from the list
void Score::Detach(IScoreObserver* observer) {
    observers.erase(
        std::remove(observers.begin(), observers.end(), observer),
        observers.end()
    );
}

// notify all observers about the score change
void Score::Notify() {
    for (auto observer : observers) {
        observer->OnScoreChanged(score);
    }
}

// draw the current score on the screen
void Score::DrawScore() const {
    DrawTextEx(font, TextFormat("%d", score), {500, 70}, 38, 2, BLACK);
}

// reset the score to 0 and notify observers
void Score::SetScore() {
    score = 0;
    Notify();
}

// update the score and notify observers
void Score::UpdateScore(int points) {
    score += points;
    Notify();
}
// observer for achievement notifications
class AchievementObserver : public IScoreObserver {
public:
    // called when score changes
    void OnScoreChanged(int newScore) override {
        // check if score is above 1000 for achievement
        if (newScore >= 1000) {
            // display achievement message on screen
            DrawTextEx(GetFontDefault(),
                      "Achievement Unlocked!",
                      Vector2{200, 200},
                      38,
                      2,
                      BLACK);
        }
    }
};

// observer for tracking high score
class HighScoreObserver : public IScoreObserver {
private:
    int highScore = 0; // stores the highest score

public:
    // called when score changes
    void OnScoreChanged(int newScore) override {
        // update high score if new score is higher
        if (newScore > highScore) {
            highScore = newScore;
        }
    }
};

// function to get current score
int Score::GetScore() const {
    return score; // return the current score
}
