#pragma once
#include "Hero.h"
#include <iostream>
using namespace std;

class Mage : public Hero {
    int mana;
public:
    Mage(string name, int str, int dex, int end, int intl, int cha, int respect, int sacredArmor, int mana);
    Mage(int mana);
    void battleCry() const override;
    void display() const override;
    void describe() const override;
    void increaseHealth(int amount);
    void displayStats() const;
    ~Mage() override;
};
