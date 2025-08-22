#ifndef HERO_H
#define HERO_H

#include "Character.h"

class Hero : public Character {
protected:
    int respect;
    int sacredArmor;
public:
    Hero(string n, int str, int dex, int end, int intl, int cha, int r, int sa)
        : Character(n, str, dex, end, intl, cha), respect(r), sacredArmor(sa) {}
    virtual ~Hero() {}
    void display() override;
    void increaseHealth(int value) override;
    virtual void learnSpell(const string& spellName) = 0;
};

#endif



