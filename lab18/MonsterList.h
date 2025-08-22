#pragma once
#include "Character.h"
#include <vector>
#include <iostream>
using namespace std;

class Monster : public Character {
protected:
    int evilness, evilArmor;

public:
    Monster(string name, vector<int> stats);
    virtual void taunt() const = 0;
    virtual void describe() const = 0;
    virtual void display() const override;
    virtual int getPowerLevel() const override;
    virtual vector<int> getStats() const override;
    virtual ~Monster();
};
