#include "Thief.h"
#include <iostream>
using namespace std;

Thief::Thief(string n, int str, int dex, int end, int intl, int cha, int evil, int evilA, int st)
    : Monster(n, str, dex, end, intl, cha, evil, evilA), stealth(st) {}

void Thief::display() {
    cout << "Thief: " << name << " Strength: " << strength << " Dexterity: " << dexterity
         << " Endurance: " << endurance << " Intelligence: " << intelligence
         << " Charisma: " << charisma << " Evilness: " << evilness
         << " Evil Armor: " << evilArmor << " Stealth: " << stealth << endl;
}

void Thief::increaseHealth(int value) {
    endurance += value;
}