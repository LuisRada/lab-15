#include "MonsterList.h"
using namespace std;

Monster::Monster(string name, vector<int> stats)
    : Character(stats), evilness(stats[6]), evilArmor(stats[7]) {
    this->name = name;
}

void Monster::display() const {
    Character::display();
    cout << "Evilness: " << evilness
         << "\nEvil Armor: " << evilArmor << endl;
}

int Monster::getPowerLevel() const {
    return strength + dexterity + endurance + intelligence + charisma + evilness + evilArmor;
}

vector<int> Monster::getStats() const {
    return {health, strength, dexterity, endurance, intelligence, charisma, evilness, evilArmor, 0};
}

Monster::~Monster() {
    cout << "Monster destructor called" << endl;
}
