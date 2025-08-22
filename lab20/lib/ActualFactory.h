#pragma once
#ifndef ACTUALFACTORY_H
#define ACTUALFACTORY_H

#include "CharacterFactory.h"
#include "Mage.h"
#include "Warrior.h"
#include "Ogre.h"
#include <string>
#include <vector>

class ActualFactory : public CharacterFactory {
public:
    Character* createHero(const std::string& type, const std::string& name, const std::vector<int>& stats) override {
        if (type == "Mage" || type == "mage") {
            return new Mage(name, stats);
        }
        if (type == "Warrior" || type == "warrior") {
            return new Warrior(name, stats);
        }
        return nullptr;
    }

    Character* createMonster(const std::string& type, const std::string& name, const std::vector<int>& stats) override {
        if (type == "Ogre" || type == "ogre") {
            return new Ogre(name, stats);
        }
        return nullptr;
    }
};

#endif