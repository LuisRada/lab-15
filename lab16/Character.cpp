#include "Character.h"
#include <iostream>
using namespace std;

Character::Character(int in_health) : health(in_health) {}
Character::Character(string name, int str, int dex, int end, int intl, int cha)
    : name(name), strength(str), dexterity(dex), endurance(end), intelligence(intl), charisma(cha) {}

string Character::getName() const { return name; }

void Character::display() const {
    cout << "Name: " << name
         << "\nStrength: " << strength
         << "\nDexterity: " << dexterity
         << "\nEndurance: " << endurance
         << "\nIntelligence: " << intelligence
         << "\nCharisma: " << charisma << endl;
}

Character::~Character() {}
