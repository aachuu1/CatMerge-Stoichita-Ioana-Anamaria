#pragma once
#include <iostream>
#include <map>
#include <string>

template<typename T>
class GameStats {
private:
    std::map<std::string, T> stats;
    std::string gameName;

public:
    explicit GameStats(const std::string& name = "CatMerge") : gameName(name) {}

    void UpdateStat(const std::string& statName, const T& value) {
        stats[statName] = value;
        std::cout << "Statistica actualizata: " << statName << " = " << value << std::endl;
    }
    template<typename U = T>
    typename std::enable_if<std::is_arithmetic<U>::value>::type
    IncrementStat(const std::string& statName, const U& amount = 1) {
        if (stats.find(statName) == stats.end()) {
            stats[statName] = amount;
        } else {
            stats[statName] += amount;
        }
        std::cout << statName << " incrementat la: " << stats[statName] << std::endl;
    }
    T GetStat(const std::string& statName) const {
        auto it = stats.find(statName);
        if (it != stats.end()) {
            return it->second;
        }
        throw std::runtime_error("Statistica nu există!");
    }

    bool HasStat(const std::string& statName) const {
        return stats.find(statName) != stats.end();
    }

    void ResetStat(const std::string& statName) {
        auto it = stats.find(statName);
        if (it != stats.end()) {
            it->second = T();
            std::cout << statName << " resetat la valoarea implicită" << std::endl;
        }
    }

    void DisplayStats() const {
        std::cout << "\n=== Statistici " << gameName << " ===" << std::endl;
        for (const auto& [name, value] : stats) {
            std::cout << name << ": " << value << std::endl;
        }
        std::cout << "==========================\n" << std::endl;
    }
};

