#include "Warrior.h"
using namespace std;

Warrior::Warrior(string name, int str, int dex, int end, int intl, int cha, int respect, int sacredArmor, int stamina)
    : Hero(name, str, dex, end, intl, cha, respect, sacredArmor), stamina(stamina) {}
void Warrior::battleCry() const { cout << "Warrior: For Glory!" << endl; }
void Warrior::display() const {
    Hero::display();
    cout << "Stamina: " << stamina << endl;
}
void Warrior::describe() const { cout << "Warrior: " << name << ", Stamina: " << stamina << endl; }
Warrior::~Warrior() { cout << "Warrior destructor called" << endl; }
