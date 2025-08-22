#pragma once
#include "Hero.h"
#include <vector>
#include <iostream>
using namespace std;

class Mage : public Hero {
public:
    Mage(string name, vector<int> stats);
    void battleCry() const override;
    void display() const override;
    void describe() const override;
    void increaseHealth(int amount) override;
    void displayStats() const override;
    int getPowerLevel() const override;
    vector<int> getStats() const override;
    ~Mage() override;
};
