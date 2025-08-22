#ifndef WARRIOR_H
#define WARRIOR_H

#include "Hero.h"

class Warrior : public Hero {
    int stamina;
public:
    Warrior(string n, int str, int dex, int end, int intl, int cha, int r, int sa, int st);
    void learnSpell(const string& spellName) override;
    void display() override;
    void increaseHealth(int value) override;
};

#endif