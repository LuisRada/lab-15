#include "Berserker.h"
#include <iostream>
using namespace std;

Berserker::Berserker(string n, int str, int dex, int end, int intl, int cha, int r, int sa, int rg)
    : Hero(n, str, dex, end, intl, cha, r, sa), rage(rg) {}

void Berserker::learnSpell(const string& spellName) {
    cout << "Berserker cannot learn spells." << endl;
}

void Berserker::display() {
    cout << "Berserker: " << name << " Strength: " << strength << " Dexterity: " << dexterity
         << " Endurance: " << endurance << " Intelligence: " << intelligence
         << " Charisma: " << charisma << " Respect: " << respect
         << " Sacred Armor: " << sacredArmor << " Rage: " << rage << endl;
}

void Berserker::increaseHealth(int value) {
    endurance += value;
}