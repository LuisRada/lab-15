#pragma once
#include "Hero.h"
#include <vector>
#include <iostream>
using namespace std;

class Berserker : public Hero {
public:
    Berserker(string name, vector<int> stats);
    void battleCry() const override;
    void display() const override;
    void describe() const override;
    int getPowerLevel() const override;
    vector<int> getStats() const override;
    ~Berserker() override;
};
