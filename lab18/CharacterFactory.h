#pragma once

#include "ArenaMode.h"
#include "AdventureMode.h"
#include <string>
#include <vector>

class CharacterFactory {
public:
    virtual ArenaMode::Character* createArenaCharacter(const std::string& type, const std::vector<int>& stats) = 0;
    virtual AdventureMode::Character* createAdventureCharacter(const std::string& type, const std::vector<int>& stats) = 0;
    virtual ~CharacterFactory() = default;
};