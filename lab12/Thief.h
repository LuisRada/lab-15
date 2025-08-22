#pragma once
#include "MonsterList.h"
#include <vector>
#include <iostream>
using namespace std;

class Thief : public Monster {
    int stealth;

public:
    Thief(string name, vector<int> stats);
    void taunt() const override;
    void display() const override;
    void describe() const override;
    int getPowerLevel() const override;
    vector<int> getStats() const override;
    ~Thief() override;
};
