#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>

class Character {
protected:
    std::string name;
    int hp;
    int power;
    int intelligence;
    int ability;
public:
    Character(const std::string& name, int hp, int power, int intelligence, int ability);
    virtual void battleCry() const = 0;
    virtual void attack() = 0;
    virtual void showInventory() const = 0;
    virtual void printStats() const;
    virtual std::string getType() const = 0;
    std::string getName() const;
    virtual ~Character();
};

#endif
