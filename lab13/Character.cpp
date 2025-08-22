#include "Character.h"
#include <iostream>
using namespace std;

Character::Character(int in_health)
    : health(in_health), strength(0), dexterity(0), endurance(0), intelligence(0), charisma(0) {}

Character::Character(string name, int str, int dex, int end, int intl, int cha)
    : name(name), strength(str), dexterity(dex), endurance(end), intelligence(intl), charisma(cha), health(0) {}

Character::Character(vector<int> stats)
    : health(stats[0]), strength(stats[1]), dexterity(stats[2]),
      endurance(stats[3]), intelligence(stats[4]), charisma(stats[5]) {}

string Character::getName() const {
    return name;
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
