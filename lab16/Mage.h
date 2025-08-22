#ifndef MAGE_H
#define MAGE_H

#include "Hero.h"

class Mage : public Hero {
    int mana;
public:
    Mage(string n, int str, int dex, int end, int intl, int cha, int r, int sa, int m);
    void learnSpell(const string& spellName) override;
    void display() override;
    void increaseHealth(int value) override;
};

#endif