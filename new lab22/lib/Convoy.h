#pragma once
#ifndef CONVOY_H
#define CONVOY_H

#include "Character.h"
#include <vector>
#include <string>
#include <iostream>

class Convoy : public Character {
private:
    std::vector<Character*> characters;

public:
    Convoy();

    Convoy(const std::string& name, const std::vector<int>& stats);

    void battleCry() const override;
    void attack() override;
    void showInventory() const override;
    void printStats() const override;
    std::string getType() const override;
    
    void add(Character* character)
    {
        characters.push_back(character);
    }
    
    void move() const override
    {
        for (const auto& c : characters)
        {
            c ->move();
        }
    }
    
    ~Convoy()
    {
        for (auto c : characters)
        {
            delete c;
        }
    }
};

#endif