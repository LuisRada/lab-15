#include "MonsterList.h"
#include <iostream>
using namespace std;

Monster::Monster(int in_health)
    : Character(in_health), evilness(0), evilArmor(0) {}

Monster::Monster(string name, int str, int dex, int end, int intl, int cha,
                 int evilness, int evilArmor)
    : Character(name, str, dex, end, intl, cha),
      evilness(evilness), evilArmor(evilArmor) {}

void Monster::display() const {
    Character::display();
    cout << "Evilness: " << evilness
         << "\nEvil Armor: " << evilArmor << endl;
}

int Monster::getPowerLevel() const {
    return strength + dexterity + endurance +
           intelligence + charisma + evilness + evilArmor;
}

Monster::~Monster() { cout << "Monster destructor called" << endl; }
