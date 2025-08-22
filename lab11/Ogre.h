#pragma once
#include "MonsterList.h"
#include <iostream>
using namespace std;

class Ogre : public Monster {
    int bruteForce;
public:
    Ogre(string name, int str, int dex, int end, int intl, int cha, int evilness, int evilArmor, int bruteForce);
    void taunt() const override;
    void display() const override;
    void describe() const override;
    ~Ogre() override;
};
