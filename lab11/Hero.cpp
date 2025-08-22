#include "Hero.h"
#include <iostream>
using namespace std;

Hero::Hero(int in_health)
    : Character(in_health), respect(0), sacredArmor(0), mana(0) {}

Hero::Hero(string name, int str, int dex, int end, int intl, int cha,
           int respect, int sacredArmor, int mana)
    : Character(name, str, dex, end, intl, cha),
      respect(respect), sacredArmor(sacredArmor), mana(mana) {}

void Hero::display() const {
    Character::display();
    cout << "Respect: " << respect
         << "\nSacred Armor: " << sacredArmor
         << "\nMana: " << mana << endl;
}

int Hero::getPowerLevel() const {
    return strength + dexterity + endurance +
           intelligence + charisma + sacredArmor + mana;
}

void battlescream::heroscreams(Hero* a) {
    a->battleCry();
}

battlescream::~battlescream() {}   // <- now matches declaration

Hero::~Hero() {
    cout << "Hero destructor called" << endl;
}

