#pragma once
#ifndef MAGE_H
#define MAGE_H

#include "Hero.h"
#include <vector>
#include <string>
#include <iostream>

class Mage : public Hero {
public:
    Mage(const std::string& name, const std::vector<int>& stats);
    void battleCry() const override;
    void attack() override;
    void display() const override;
    void describe() const override;
    void increaseHealth(int amount);
    void displayStats() const;
    int getPowerLevel() const override;
    std::vector<int> getStats() const override;
    ~Mage() override;
};

#endif

