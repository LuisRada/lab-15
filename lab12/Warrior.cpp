#include "Warrior.h"
using namespace std;

Warrior::Warrior(string name, vector<int> stats)
    : Hero(name, stats) {}

void Warrior::battleCry() const {
    cout << "Warrior: For Glory!" << endl;
}

void Warrior::display() const {
    Hero::display();
}

void Warrior::describe() const {
    cout << "Warrior: " << name << ", Stamina: " << mana << endl;
}

int Warrior::getPowerLevel() const {
    return strength + dexterity + endurance + intelligence + charisma + sacredArmor + mana;
}

vector<int> Warrior::getStats() const {
    return {health, strength, dexterity, endurance, intelligence, charisma, respect, sacredArmor, mana};
}

Warrior::~Warrior() {
    cout << "Warrior destructor called" << endl;
}
