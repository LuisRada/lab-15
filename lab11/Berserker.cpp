#include "Berserker.h"
using namespace std;

Berserker::Berserker(string name, int str, int dex, int end, int intl, int cha, int respect, int sacredArmor, int rage)
    : Hero(name, str, dex, end, intl, cha, respect, sacredArmor), rage(rage) {}
void Berserker::enhance() { strength += 5; rage += 10; }
void Berserker::battleCry() const { cout << "Berserker: For Glory!" << endl; }
void Berserker::display() const {
    Hero::display();
    cout << "Rage: " << rage << endl;
}
void Berserker::describe() const { cout << "Berserker: " << name << ", Rage: " << rage << endl; }
Berserker::~Berserker() { cout << "Berserker destructor called" << endl; }
