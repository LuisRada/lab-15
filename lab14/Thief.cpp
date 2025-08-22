#include "Thief.h"
using namespace std;

Thief::Thief(string name, vector<int> stats)
    : Monster(name, stats), stealth(stats[8]) {}

void Thief::taunt() const {
    cout << "Thief: You can't catch me!" << endl;
}

void Thief::display() const {
    Monster::display();
    cout << "Stealth: " << stealth << endl;
}

void Thief::describe() const {
    cout << "Thief: " << name << ", Stealth: " << stealth << endl;
}

int Thief::getPowerLevel() const {
    return strength + dexterity + endurance + intelligence + charisma + evilness + evilArmor + stealth;
}

vector<int> Thief::getStats() const {
    return {health, strength, dexterity, endurance, intelligence, charisma, evilness, evilArmor, stealth};
}

Thief::~Thief() {
    cout << "Thief destructor called" << endl;
}
