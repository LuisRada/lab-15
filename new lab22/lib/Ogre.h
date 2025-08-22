#pragma once
#ifndef OGRE_H
#define OGRE_H

#include "Character.h"
#include <vector>
#include <string>
#include <iostream>

class Ogre : public Character {
private:
    int evilness;
    std::vector<std::string> inventory;
public:
    Ogre(const std::string& name, const std::vector<int>& stats);
    void battleCry() const override;
    void attack() override;
    void showInventory() const override;
    void printStats() const override;
    std::string getType() const override;
    ~Ogre() override;
};

#endif
