#pragma once
#include "Character.h"
#include <vector>
#include <iostream>
using namespace std;

class Hero : public Character {
protected:
    int respect, sacredArmor, mana;

public:
    Hero(string name, vector<int> stats);
    virtual void battleCry() const = 0;
    virtual void describe() const = 0;
    virtual void display() const override;
    virtual int getPowerLevel() const override;
    virtual vector<int> getStats() const override;
    virtual void increaseHealth(int amount);
    virtual void displayStats() const;
    virtual ~Hero();
};

class battlescream {
public:
    void heroscreams(Hero* a);
    ~battlescream();
};
