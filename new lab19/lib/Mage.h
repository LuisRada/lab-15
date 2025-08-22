#pragma once
#ifndef MAGE_H
#define MAGE_H

#include "Character.h"
#include <vector>
#include <string>
#include <iostream>

class Mage : public Character {
private:
    int mana;
    std::vector<std::string> inventory;
public:
    Mage(const std::string& name, const std::vector<int>& stats);
    void battleCry() const override;
    void attack() override;
    void showInventory() const override;
    void printStats() const override;
    std::string getType() const override;
    ~Mage() override;
};

#endif