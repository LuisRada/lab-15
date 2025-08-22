#include "Mage.h"
using namespace std;

Mage::Mage(string name, vector<int> stats)
    : Hero(name, stats) {}

void Mage::battleCry() const {
    cout << "Mage: Fireball!" << endl;
}

void Mage::display() const {
    Hero::display();
}

void Mage::describe() const {
    cout << "Mage: " << name << ", Mana: " << mana << endl;
}

void Mage::increaseHealth(int amount) {
    health += amount;
}

void Mage::displayStats() const {
    display();
}

int Mage::getPowerLevel() const {
    return strength + dexterity + endurance + intelligence + charisma + sacredArmor + mana;
}

vector<int> Mage::getStats() const {
    return {health, strength, dexterity, endurance, intelligence, charisma, respect, sacredArmor, mana};
}

Mage::~Mage() {
    cout << "Mage destructor called" << endl;
}
