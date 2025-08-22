#include "Warrior.h"
#include <iostream>
using namespace std;

Warrior::Warrior(string n, int str, int dex, int end, int intl, int cha, int r, int sa, int st)
    : Hero(n, str, dex, end, intl, cha, r, sa), stamina(st) {}

void Warrior::learnSpell(const string& spellName) {
    cout << "Warrior cannot learn spells." << endl;
}

void Warrior::display() {
    cout << "Warrior: " << name << " Strength: " << strength << " Dexterity: " << dexterity
         << " Endurance: " << endurance << " Intelligence: " << intelligence
         << " Charisma: " << charisma << " Respect: " << respect
         << " Sacred Armor: " << sacredArmor << " Stamina: " << stamina << endl;
}

void Warrior::increaseHealth(int value) {
    endurance += value;
}
