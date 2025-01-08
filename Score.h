#pragma once
#include "raylib.h"
#include <vector>

class IScoreObserver {
public:
    virtual ~IScoreObserver() = default;
    virtual void OnScoreChanged(int newScore) = 0;
};

class IScoreSubject {
public:
    virtual ~IScoreSubject() = default;
    virtual void Attach(IScoreObserver* observer) = 0;
    virtual void Detach(IScoreObserver* observer) = 0;
    virtual void Notify() = 0;
};

class Score : public IScoreSubject {
private:
    int score;
    Font font{};
    std::vector<IScoreObserver*> observers;

public:
    explicit Score(int score = 0);
    ~Score() override;

    void Attach(IScoreObserver* observer) override;
    void Detach(IScoreObserver* observer) override;
    void Notify() override;

    void SetScore();
    void UpdateScore(int points);
    void DrawScore() const;
    int GetScore() const;
    [[nodiscard]] const int& getScore() const {
        return score;
    }
};