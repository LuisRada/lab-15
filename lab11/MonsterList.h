#pragma once
#include "Character.h"
#include <iostream>
using namespace std;

class Monster : public Character {
protected:
    int evilness, evilArmor;
public:
    Monster(int in_health);
    Monster(string name, int str, int dex, int end, int intl, int cha,
            int evilness, int evilArmor);

    virtual void taunt() const = 0;
    virtual void describe() const = 0;
    virtual void display() const override;
    virtual int getPowerLevel() const override;
    virtual ~Monster();
};
