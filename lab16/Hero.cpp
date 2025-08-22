#include "Hero.h"
#include <iostream>
using namespace std;

void Hero::display() {
    cout << "Hero: " << name << " Strength: " << strength << " Dexterity: " << dexterity
         << " Endurance: " << endurance << " Intelligence: " << intelligence
         << " Charisma: " << charisma << " Respect: " << respect
         << " Sacred Armor: " << sacredArmor << endl;
}

void Hero::increaseHealth(int value) {
    endurance += value;
}
