#pragma once

#include "CharacterFactory.h"
#include <string>
#include <vector>

class ActualFactory : public CharacterFactory {
public:
    ArenaMode::Character* createArenaCharacter(const std::string& type, const std::vector<int>& stats) override {
        if (type == "Mage" || type == "mage") {
            return new ArenaMode::Mage(stats);
        } else if (type == "Warrior" || type == "warrior") {
            return new ArenaMode::Warrior(stats);
        } else if (type == "Thief" || type == "thief") {
            return new ArenaMode::Thief(stats);
        } else if (type == "Ogre" || type == "ogre") {
            return new ArenaMode::Ogre(stats);
        } else {
            return nullptr;
        }
    }

    AdventureMode::Character* createAdventureCharacter(const std::string& type, const std::vector<int>& stats) override {
        if (type == "Mage" || type == "mage") {
            return new AdventureMode::Mage(stats);
        } else if (type == "Warrior" || type == "warrior") {
            return new AdventureMode::Warrior(stats);
        } else if (type == "Thief" || type == "thief") {
            return new AdventureMode::Thief(stats);
        } else if (type == "Ogre" || type == "ogre") {
            return new AdventureMode::Ogre(stats);
        } else {
            return nullptr;
        }
    }
};