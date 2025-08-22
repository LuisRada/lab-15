#include "Hero.h"
using namespace std;

Hero::Hero(string name, vector<int> stats)
    : Character(stats), respect(stats[6]), sacredArmor(stats[7]), mana(stats[8]) {
    this->name = name;
}

void Hero::display() const {
    Character::display();
    cout << "Respect: " << respect
         << "\nSacred Armor: " << sacredArmor
         << "\nMana: " << mana << endl;
}

int Hero::getPowerLevel() const {
    return strength + dexterity + endurance + intelligence + charisma + sacredArmor + mana;
}

vector<int> Hero::getStats() const {
    return {health, strength, dexterity, endurance, intelligence, charisma, respect, sacredArmor, mana};
}

void Hero::increaseHealth(int amount) {
    health += amount;
}

void Hero::displayStats() const {
    display();
}

void battlescream::heroscreams(Hero* a) {
    a->battleCry();
}

battlescream::~battlescream() {}

Hero::~Hero() {
    cout << "Hero destructor called" << endl;
}

