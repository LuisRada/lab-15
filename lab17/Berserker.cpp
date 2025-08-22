#include "Berserker.h"
using namespace std;

Berserker::Berserker(string name, vector<int> stats)
    : Hero(name, stats) {}

void Berserker::battleCry() const {
    cout << "Berserker: For Glory!" << endl;
}

void Berserker::display() const {
    Hero::display();
}

void Berserker::describe() const {
    cout << "Berserker: " << name << ", Rage: " << mana << endl;
}

int Berserker::getPowerLevel() const {
    return strength + dexterity + endurance + intelligence + charisma + sacredArmor + mana;
}

vector<int> Berserker::getStats() const {
    return {health, strength, dexterity, endurance, intelligence, charisma, respect, sacredArmor, mana};
}

Berserker::~Berserker() {
    cout << "Berserker destructor called" << endl;
}
