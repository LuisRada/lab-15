#include "Thief.h"
using namespace std;

Thief::Thief(string name, int str, int dex, int end, int intl, int cha, int evilness, int evilArmor, int stealth)
    : Monster(name, str, dex, end, intl, cha, evilness, evilArmor), stealth(stealth) {}
void Thief::enhance() { dexterity += 5; stealth += 10; }
void Thief::taunt() const { cout << "Thief: You can't catch me!" << endl; }
void Thief::display() const {
    Monster::display();
    cout << "Stealth: " << stealth << endl;
}
void Thief::describe() const { cout << "Thief: " << name << ", Stealth: " << stealth << endl; }
Thief::~Thief() { cout << "Thief destructor called" << endl; }
