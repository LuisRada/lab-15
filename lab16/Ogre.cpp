#include "Ogre.h"
using namespace std;

Ogre::Ogre(string name, int str, int dex, int end, int intl, int cha, int evilness, int evilArmor, int bruteForce)
    : Monster(name, str, dex, end, intl, cha, evilness, evilArmor), bruteForce(bruteForce) {}
void Ogre::taunt() const { cout << "Ogre: Feel my wrath!" << endl; }
void Ogre::display() const { Monster::display(); }
void Ogre::describe() const { cout << "Ogre: " << name << ", Brute Force: " << bruteForce << endl; }
Ogre::~Ogre() { cout << "Ogre destructor called" << endl; }
