#pragma once
#include <iostream>
#include <map>
#include <string>

template<typename t>
class GameStats {
private:
    std::map<std::string, t> stats; // map for storing stat names and values
    std::string gamename; // game name (default: "catmerge")

public:
    explicit GameStats(const std::string& name = "catmerge") : gamename(name) {} // constructor to set game name

    // update a stat with a new value
    void UpdateStat(const std::string& statname, const t& value) {
        stats[statname] = value;
        std::cout << "statistica actualizata: " << statname << " = " << value << std::endl;
    }

    // increment stat value (only for numeric types)
    template<typename u = t>
    typename std::enable_if<std::is_arithmetic<u>::value>::type
    IncrementStat(const std::string& statname, const u& amount = 1) {
        if (stats.find(statname) == stats.end()) {
            stats[statname] = amount; // init stat if not found
        } else {
            stats[statname] += amount; // increment existing stat
        }
        std::cout << statname << " incrementat la: " << stats[statname] << std::endl;
    }

    // get value of a stat
    t GetStat(const std::string& statname) const {
        auto it = stats.find(statname);
        if (it != stats.end()) {
            return it->second; // return stat value
        }
        throw std::runtime_error("statistica nu există!"); // error if stat not found
    }

    // check if stat exists
    bool HasStat(const std::string& statname) const {
        return stats.find(statname) != stats.end();
    }

    // reset stat to default value
    void ResetStat(const std::string& statname) {
        auto it = stats.find(statname);
        if (it != stats.end()) {
            it->second = t(); // reset to default value
            std::cout << statname << " resetat la valoarea implicită" << std::endl;
        }
    }

    // display all game stats
    void SisplayStats() const {
        std::cout << "\n=== statistici " << gamename << " ===" << std::endl;
        for (const auto& [name, value] : stats) {
            std::cout << name << ": " << value << std::endl;
        }
    }
};
