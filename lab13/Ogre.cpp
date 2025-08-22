#include "Ogre.h"
using namespace std;

Ogre::Ogre(string name, vector<int> stats)
    : Monster(name, stats), bruteForce(stats[8]) {}

void Ogre::taunt() const {
    cout << "Ogre: Feel my wrath!" << endl;
}

void Ogre::display() const {
    Monster::display();
}

void Ogre::describe() const {
    cout << "Ogre: " << name << ", Brute Force: " << bruteForce << endl;
}

int Ogre::getPowerLevel() const {
    return strength + dexterity + endurance + intelligence + charisma + evilness + evilArmor + bruteForce;
}

vector<int> Ogre::getStats() const {
    return {health, strength, dexterity, endurance, intelligence, charisma, evilness, evilArmor, bruteForce};
}

Ogre::~Ogre() {
    cout << "Ogre destructor called" << endl;
}
