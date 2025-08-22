#ifndef BERSERKER_H
#define BERSERKER_H

#include "Hero.h"

class Berserker : public Hero {
    int rage;
public:
    Berserker(string n, int str, int dex, int end, int intl, int cha, int r, int sa, int rg);
    void learnSpell(const string& spellName) override;
    void display() override;
    void increaseHealth(int value) override;
};

#endif