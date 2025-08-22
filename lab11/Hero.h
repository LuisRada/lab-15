#pragma once
#include "Character.h"
#include <iostream>
using namespace std;

class Hero : public Character {
protected:
    int respect, sacredArmor;
    int mana;
public:
    Hero(int in_health);
    Hero(string name, int str, int dex, int end, int intl, int cha,
         int respect, int sacredArmor, int mana = 0);
    virtual void battleCry() const = 0;
    virtual void describe() const = 0;
    virtual void display() const override;
    virtual int getPowerLevel() const override;
    virtual ~Hero();
};

class battlescream {
public:
    void heroscreams(Hero* a);
    ~battlescream();   // <- add this line
};



