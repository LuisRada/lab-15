#pragma once
#include "MonsterList.h"
#include <vector>
#include <iostream>
using namespace std;

class Ogre : public Monster {
    int bruteForce;

public:
    Ogre(string name, vector<int> stats);
    void taunt() const override;
    void display() const override;
    void describe() const override;
    int getPowerLevel() const override;
    vector<int> getStats() const override;
    ~Ogre() override;
};
