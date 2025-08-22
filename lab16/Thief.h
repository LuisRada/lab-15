#ifndef THIEF_H
#define THIEF_H

#include "MonsterList.h"

class Thief : public Monster {
    int stealth;
public:
    Thief(string n, int str, int dex, int end, int intl, int cha, int evil, int evilA, int st);
    void display() override;
    void increaseHealth(int value) override;
};

#endif

