#pragma once
#ifndef HERO_H
#define HERO_H

#include "Character.h"
#include <string>
#include <vector>

class Hero : public Character {
public:
    Hero(const std::string& name, const std::vector<int>& stats);
    virtual void battleCry() const = 0;
    virtual ~Hero() = default;
};

#endif