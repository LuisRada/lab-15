#pragma once
#include "Hero.h"
#include <iostream>
using namespace std;

class Warrior : public Hero {
    int stamina;
public:
    Warrior(string name, int str, int dex, int end, int intl, int cha, int respect, int sacredArmor, int stamina);
    void battleCry() const override;
    void display() const override;
    void describe() const override;
    ~Warrior() override;
};
