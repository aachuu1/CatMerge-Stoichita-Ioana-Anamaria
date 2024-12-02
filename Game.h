#pragma once

#include <raylib.h>
#include <vector>
#include <memory>
#include <random>

#include "Cat.h"
#include "Boundary.h"
#include "Score.h"
#include "CatPandispan.h"
#include "CatHoratiu.h"
#include "CatPedro.h"

// Clasa singleton Game care gestionează logica principală a jocului
class Game {
private:
    static Game* instance;         // Instanță singleton
    Font font{};                   // Font pentru afișarea textelor
    Boundary boundary;             // Obiect pentru limitele jocului
    Score score;                   // Obiect pentru gestionarea scorului
    std::vector<std::unique_ptr<Cat>> cats; // Vector de pisici
    int lastSpawnTime{};           // Timpul ultimei generări de pisici

    Game();                        // Constructor privat
    ~Game();                       // Destructor

    void CheckForInvalidKeyPress();          // Verifică apăsările greșite de taste
    void UpdateCats();                       // Actualizează comportamentul pisicilor
    void AddNewCat();                        // Adaugă o nouă pisică
    void DrawUI() const;                     // Desenează interfața grafică a jocului

public:
    // Prevenirea copierei sau mutării instanței
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;
    Game(Game&&) = delete;
    Game& operator=(Game&&) = delete;

    static Game& GetInstance();              // Returnează instanța singleto
    void Run();                              // Rulează bucla principală a jocului

    [[nodiscard]] Score GetScore() const;    // Returnează scorul curent
    [[nodiscard]] Boundary GetBoundary() const; // Returnează limitele jocului
};

