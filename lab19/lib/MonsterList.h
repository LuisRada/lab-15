#pragma once
#ifndef MONSTERLIST_H
#define MONSTERLIST_H

#include "Character.h"
#include <vector>
#include <string>
#include <iostream>

class Monster : public Character {
public:
    Monster(const std::string& name, const std::vector<int>& stats);
    virtual void taunt() const = 0;
    virtual void describe() const = 0;
    void display() const override;
    int getPowerLevel() const override;
    std::vector<int> getStats() const override;
    virtual ~Monster();
};

#endif
