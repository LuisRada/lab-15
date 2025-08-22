#pragma once
#ifndef CHARACTERFACTORY_H
#define CHARACTERFACTORY_H

#include <string>
#include <vector>
#include "Character.h"

class CharacterFactory {
public:
    virtual Character* createHero(const std::string& type, const std::string& name, const std::vector<int>& stats) = 0;
    virtual Character* createMonster(const std::string& type, const std::string& name, const std::vector<int>& stats) = 0;
    virtual ~CharacterFactory() = default;
};

#endif