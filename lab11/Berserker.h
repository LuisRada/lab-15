#pragma once
#include "Hero.h"
#include <iostream>
using namespace std;

class Berserker : public Hero {
    int rage;
public:
    Berserker(string name, int str, int dex, int end, int intl, int cha, int respect, int sacredArmor, int rage);
    void enhance();
    void battleCry() const override;
    void display() const override;
    void describe() const override;
    ~Berserker() override;
};

