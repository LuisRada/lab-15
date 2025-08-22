#pragma once
#ifndef WARRIOR_H
#define WARRIOR_H

#include "Hero.h"
#include <vector>
#include <string>
#include <iostream>

class Warrior : public Hero {
public:
    Warrior(const std::string& name, const std::vector<int>& stats);
    void battleCry() const override;
    void attack() override;
    void display() const override;
    void describe() const override;
    int getPowerLevel() const override;
    std::vector<int> getStats() const override;
    ~Warrior() override;
};

#endif
