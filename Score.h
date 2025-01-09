#pragma once
#include "raylib.h"
#include <vector>

// interface for score observers
class IScoreObserver {
public:
    virtual ~IScoreObserver() = default;
    virtual void OnScoreChanged(int newScore) = 0; // method to handle score changes
};

// interface for the score subject (can have multiple observers)
class IScoreSubject {
public:
    virtual ~IScoreSubject() = default;
    virtual void Attach(IScoreObserver* observer) = 0; // method to attach an observer
    virtual void Detach(IScoreObserver* observer) = 0; // method to detach an observer
    virtual void Notify() = 0; // method to notify observers of score change
};

// score class that manages score and notifies observers
class Score : public IScoreSubject {
private:
    int score; // current score value
    Font font{}; // font for drawing the score
    std::vector<IScoreObserver*> observers; // list of observers to notify

public:
    explicit Score(int score = 0); // constructor with default score 0
    ~Score() override; // destructor

    // methods for attaching, detaching, and notifying observers
    void Attach(IScoreObserver* observer) override;
    void Detach(IScoreObserver* observer) override;
    void Notify() override;

    // methods for updating and setting the score
    void SetScore();
    void UpdateScore(int points);

    // method to draw the score on screen
    void DrawScore() const;

    // method to get the current score
    int GetScore() const;

    // additional method to get score by reference (for efficiency)
    [[nodiscard]] const int& getScore() const {
        return score;
    }
};
