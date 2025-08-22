#pragma once
#include "MonsterList.h"
#include <iostream>
using namespace std;

class Thief : public Monster {
    int stealth;
public:
    Thief(string name, int str, int dex, int end, int intl, int cha, int evilness, int evilArmor, int stealth);
    void enhance();
    void taunt() const override;
    void display() const override;
    void describe() const override;
    ~Thief() override;
};


