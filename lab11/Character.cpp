#include "Character.h"
#include <iostream>
using namespace std;

Character::Character(int in_health)
    : name(""), strength(0), dexterity(0),
      endurance(0), intelligence(0), charisma(0),
      health(in_health)
{}

Character::Character(string name, int str, int dex, int end, int intl, int cha)
    : name(name),
      strength(str),
      dexterity(dex),
      endurance(end),
      intelligence(intl),
      charisma(cha)
{
    health = endurance * 10;
}

string Character::getName() const {
    return name;
}

int Character::getHealth() const {
    return health;
}

void Character::increaseHealth(int value) {
    health += value;
}

void Character::display() const {
    cout << "Name: " << name
         << "\nStrength: " << strength
         << "\nDexterity: " << dexterity
         << "\nEndurance: " << endurance
         << "\nIntelligence: " << intelligence
         << "\nCharisma: " << charisma
         << "\nHealth: " << health << endl;
}

Character::~Character() {}
